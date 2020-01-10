/*
 * spi-def.c
 *
 *  Created on: Nov 29, 2019
 *      Author: grzegorz
 */

// Standard library code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tcp_raw.h>

// SCPI library code
#include "scpi/scpi.h"
#include "lwip/tcpip.h"

#include "spi_flash.h"
#include "scpi_def.h"
#include "main.h"
#include "defines.h"
#include "matrix.h"

extern struct echo_state *es_scpi;
extern struct tcp_pcb *tcp_echoserver_pcb;

extern SPI_HandleTypeDef hspi4;
extern SPI_HandleTypeDef hspi5;

struct _scpi_channel_value_t {
    int32_t row;
    int32_t col;
};

typedef struct _scpi_channel_value_t scpi_channel_value_t;


static void SCPI_CreateSPICommands(scpi_channel_value_t* array, size_t index, uint8_t state)
{
	uint32_t spi_cmd_idx = 0;

	for(uint8_t i = 0; i < SPI_CMD_SIZE; i++)
	{
		matrix.spi_commands[i].enabled = FALSE;
	}

	for(uint16_t x = 0; x < index; x++)
	{
		spi_cmd_idx = matrix.relays[x].index;

		if(CLOSE == state)
		{
			matrix.spi_commands[spi_cmd_idx].tx_tmp |= (uint16_t)(1U << matrix.relays[array[x].row].MCZ33996.out);

		}
		else if (OPEN == state)
		{
			matrix.spi_commands[spi_cmd_idx].tx_tmp &= ~(uint16_t)(1U << matrix.relays[array[x].row].MCZ33996.out);
		}

		matrix.spi_commands[spi_cmd_idx].enabled = TRUE;

	}

	for(uint8_t i = 0; i < SPI_CMD_SIZE; i++)
	{
		matrix.spi_commands[i].tx_data[0] = 0x00;
		matrix.spi_commands[i].tx_data[1] = (uint8_t)(matrix.spi_commands[i].tx_tmp >> 8);
		matrix.spi_commands[i].tx_data[2] = (uint8_t)(matrix.spi_commands[i].tx_tmp);
	}
}

static void SCPI_MatrixStatusUpdate(scpi_channel_value_t* array, size_t index, uint8_t state)
{

	for(uint16_t x = 0; x < index; x++)
	{

		if(CLOSE == state)
		{
			matrix.relays[array[x].row].state = CLOSE;

		}
		else if(OPEN == state)
		{
			matrix.relays[array[x].row].state = OPEN;
		}
	}
}

static scpi_result_t SCPI_ChannelList(scpi_t *context, scpi_channel_value_t* array, size_t* index, size_t max_row, size_t max_col, size_t max_dim)
{
    scpi_parameter_t channel_list_param;
    size_t chanlst_idx; /* index for channel list */
    size_t arr_idx = 0; /* index for array */
    size_t n, m = 1; /* counters for row (n) and columns (m) */

    /* get channel list */
    if (!SCPI_Parameter(context, &channel_list_param, TRUE))
    {
        return FALSE;
    }
    else
    {
        scpi_expr_result_t res;
        scpi_bool_t is_range;
        int32_t values_from[max_dim];
        int32_t values_to[max_dim];
        size_t dimensions;

        bool for_stop_row = FALSE; /* true if iteration for rows has to stop */
        bool for_stop_col = FALSE; /* true if iteration for columns has to stop */
        int32_t dir_row = 1; /* direction of counter for rows, +/-1 */
        int32_t dir_col = 1; /* direction of counter for columns, +/-1 */

        /* the next statement is valid usage and it gets only real number of dimensions for the first item (index 0) */
        if (!SCPI_ExprChannelListEntry(context, &channel_list_param, 0, &is_range, NULL, NULL, 0, &dimensions))
         {
            chanlst_idx = 0; /* call first index */
            arr_idx = 0; /* set arr_idx to 0 */
            do
            { /* if valid, iterate over channel_list_param index while res == valid (do-while cause we have to do it once) */
                res = SCPI_ExprChannelListEntry(context, &channel_list_param, chanlst_idx, &is_range, values_from, values_to, 4, &dimensions);
                if (is_range == FALSE)
                { /* still can have multiple dimensions */
                    if (dimensions == 1)
                    {
                        /* here we have our values
                         * row == values_from[0]
                         * col == 0 (fixed number)
                         * call a function or something */
                        array[arr_idx].row = values_from[0];
                        array[arr_idx].col = 0;
                    }
                    else if (dimensions == 2)
                    {
                        /* here we have our values
                         * row == values_fom[0]
                         * col == values_from[1]
                         * call a function or something */
                        array[arr_idx].row = values_from[0];
                        array[arr_idx].col = values_from[1];
                    }
                    else
                    {
                        return FALSE;
                    }
                    arr_idx++; /* inkrement array where we want to save our values to, not neccessary otherwise */
                    if (arr_idx >= max_row * max_col)
                    {
                        return FALSE;
                    }
                }
                else if (is_range == TRUE)
                {
                    if (values_from[0] > values_to[0])
                    {
                        dir_row = -1; /* we have to decrement from values_from */
                    } else { /* if (values_from[0] < values_to[0]) */
                        dir_row = +1; /* default, we increment from values_from */
                    }

                    /* iterating over rows, do it once -> set for_stop_row = false
                     * needed if there is channel list index isn't at end yet */
                    for_stop_row = FALSE;
                    for (n = values_from[0]; for_stop_row == FALSE; n += dir_row)
                    {
                        /* usual case for ranges, 2 dimensions */
                        if (dimensions == 2) {
                            if (values_from[1] > values_to[1]) {
                                dir_col = -1;
                            }
                            else if (values_from[1] < values_to[1])
                            {
                                dir_col = +1;
                            }
                            /* iterating over columns, do it at least once -> set for_stop_col = false
                             * needed if there is channel list index isn't at end yet */
                            for_stop_col = FALSE;
                            for (m = values_from[1]; for_stop_col == FALSE; m += dir_col)
                            {
                                /* here we have our values
                                 * row == n
                                 * col == m
                                 * call a function or something */
                                array[arr_idx].row = n;
                                array[arr_idx].col = m;
                                arr_idx++;
                                if (arr_idx >= max_row * max_col)
                                {
                                    return FALSE;
                                }
                                if (m == (size_t)values_to[1])
                                {
                                    /* endpoint reached, stop column for-loop */
                                    for_stop_col = TRUE;
                                }
                            }
                            /* special case for range, example: (@2!1) */
                        }
                        else if (dimensions == 1)
                        {
                            /* here we have values
                             * row == n
                             * col == 0 (fixed number)
                             * call function or sth. */
                            array[arr_idx].row = n;
                            array[arr_idx].col = 0;
                            arr_idx++;
                            if (arr_idx >= max_row * max_col)
                            {
                                return FALSE;
                            }
                        }
                        if (n == (size_t)values_to[0])
                        {
                            /* endpoint reached, stop row for-loop */
                            for_stop_row = TRUE;
                        }
                    }


                }
                else
                {
                    return FALSE;
                }
                /* increase index */
                chanlst_idx++;
            } while (SCPI_EXPR_OK == SCPI_ExprChannelListEntry(context, &channel_list_param, chanlst_idx, &is_range, values_from, values_to, 4, &dimensions));
            /* while checks, whether incremented index is valid */
        }
            *index = arr_idx;
     }

    return TRUE;
}


static uint8_t SCPI_StringToIP4Array(const int8_t* ip_string, uint8_t* ip_array)
{

    /* A pointer to the next digit to process. */
    const int8_t* start;

    start = ip_string;
    for (uint8_t i = 0; i < 4; i++)
    {
        /* The digit being processed. */
        uint8_t c;
        /* The value of this byte. */
        uint16_t n = 0;
        while (1)
        {
            c = * start;
            start++;
            if (c >= '0' && c <= '9')
            {
                n *= 10;
                n += c - '0';
            }
            /* We insist on stopping at "." if we are still parsing
               the first, second, or third numbers. If we have reached
               the end of the numbers, we will allow any character. */
            else if ((i < 3 && c == '.') || i == 3)
            {
                break;
            }
            else
            {
                return NET_STR_WRONG_FORMAT;
            }
        }
        if (n >= 256)
        {
            return NET_STR_WRONG_NUMBER;
        }
        ip_array[i] = n;
    }

    return NET_STR_OK;
}

static uint8_t SCPI_StringToMACArray(const uint8_t* MAC_string, uint8_t* MAC_array)
{
    int32_t values[6];

    if(6 == sscanf(MAC_string, "%x:%x:%x:%x:%x:%x%*c",
    &values[0], &values[1], &values[2],
    &values[3], &values[4], &values[5]))
    {
        for (uint8_t i = 0; i < 6; i++)
        MAC_array[i] = (uint8_t)values[i];
    }
    else if (6 == sscanf(MAC_string, "%x-%x-%x-%x-%x-%x%*c",
    &values[0], &values[1], &values[2],
    &values[3], &values[4], &values[5]))
    {
        for (uint8_t i = 0; i < 6; i++)
        MAC_array[i] = (uint8_t)values[i];
    }
    else
    {}

    return NET_STR_OK;
}

static void SCPI_SPITransmit(uint8_t cs_number, uint8_t spi_number, uint8_t index)
{
	uint32_t timeout = 1000;

	switch(matrix.spi_commands[index].cs)
	{
	case CS0: HAL_GPIO_WritePin(RELAY1_nCS0_GPIO_Port, RELAY1_nCS0_Pin, OFF); break;
	case CS1: HAL_GPIO_WritePin(RELAY1_nCS1_GPIO_Port, RELAY1_nCS1_Pin, OFF); break;
	case CS2: HAL_GPIO_WritePin(RELAY1_nCS2_GPIO_Port, RELAY1_nCS2_Pin, OFF); break;
	case CS3: HAL_GPIO_WritePin(RELAY1_nCS3_GPIO_Port, RELAY1_nCS3_Pin, OFF); break;
	case CS4: HAL_GPIO_WritePin(RELAY1_nCS4_GPIO_Port, RELAY1_nCS4_Pin, OFF); break;
	case CS5: HAL_GPIO_WritePin(RELAY2_nCS0_GPIO_Port, RELAY2_nCS0_Pin, OFF); break;
	case CS6: HAL_GPIO_WritePin(RELAY2_nCS1_GPIO_Port, RELAY2_nCS1_Pin, OFF); break;
	case CS7: HAL_GPIO_WritePin(RELAY2_nCS2_GPIO_Port, RELAY2_nCS2_Pin, OFF); break;
	case CS8: HAL_GPIO_WritePin(RELAY2_nCS3_GPIO_Port, RELAY2_nCS3_Pin, OFF); break;
	case CS9: HAL_GPIO_WritePin(RELAY2_nCS4_GPIO_Port, RELAY2_nCS4_Pin, OFF); break;
	}

	if(SPI4_ID == matrix.spi_commands[index].spi)
	{
		HAL_SPI_Transmit(&hspi4, matrix.spi_commands[index].tx_data, 3, timeout);
	}
	else if(SPI5_ID == matrix.spi_commands[index].spi)
	{
		HAL_SPI_Transmit(&hspi5, matrix.spi_commands[index].tx_data, 3, timeout);
	}

	switch(matrix.spi_commands[index].cs)
	{
	case CS0: HAL_GPIO_WritePin(RELAY1_nCS0_GPIO_Port, RELAY1_nCS0_Pin, ON); break;
	case CS1: HAL_GPIO_WritePin(RELAY1_nCS1_GPIO_Port, RELAY1_nCS1_Pin, ON); break;
	case CS2: HAL_GPIO_WritePin(RELAY1_nCS2_GPIO_Port, RELAY1_nCS2_Pin, ON); break;
	case CS3: HAL_GPIO_WritePin(RELAY1_nCS3_GPIO_Port, RELAY1_nCS3_Pin, ON); break;
	case CS4: HAL_GPIO_WritePin(RELAY1_nCS4_GPIO_Port, RELAY1_nCS4_Pin, ON); break;
	case CS5: HAL_GPIO_WritePin(RELAY2_nCS0_GPIO_Port, RELAY2_nCS0_Pin, ON); break;
	case CS6: HAL_GPIO_WritePin(RELAY2_nCS1_GPIO_Port, RELAY2_nCS1_Pin, ON); break;
	case CS7: HAL_GPIO_WritePin(RELAY2_nCS2_GPIO_Port, RELAY2_nCS2_Pin, ON); break;
	case CS8: HAL_GPIO_WritePin(RELAY2_nCS3_GPIO_Port, RELAY2_nCS3_Pin, ON); break;
	case CS9: HAL_GPIO_WritePin(RELAY2_nCS4_GPIO_Port, RELAY2_nCS4_Pin, ON); break;
	}

}

void SCPI_SendSPICommand()
{
	for(uint8_t i = 0; i < SPI_CMD_SIZE; i++)
	{
		if(matrix.spi_commands[i].enabled)
		{
			SCPI_SPITransmit(matrix.spi_commands[i].cs, matrix.spi_commands[i].spi, i);
		}
	}
}

size_t SCPI_Write(scpi_t* context, const char * data, size_t len)
{
    (void) context;
    //err_t wr_err = ERR_OK;

    strcat(es_scpi->p->payload, data);

    es_scpi->p->len += len;
    return es_scpi->p->len;
}

scpi_result_t SCPI_Flush(scpi_t* context)
{
    (void) context;

    return SCPI_RES_OK;
}

int SCPI_Error(scpi_t* context, int_fast16_t err)
{
    (void) context;

    fprintf(stderr, "**ERROR: %d, \"%s\"\r\n", (int16_t) err, SCPI_ErrorTranslate(err));
    return 0;
}

scpi_result_t SCPI_Control(scpi_t* context, scpi_ctrl_name_t ctrl, scpi_reg_val_t val)
{
    (void) context;

    if (SCPI_CTRL_SRQ == ctrl) {
        fprintf(stderr, "**SRQ: 0x%X (%d)\r\n", val, val);
    } else {
        fprintf(stderr, "**CTRL %02x: 0x%X (%d)\r\n", ctrl, val, val);
    }
    return SCPI_RES_OK;
}

scpi_result_t SCPI_Reset(scpi_t* context)
{
    (void) context;

    NVIC_SystemReset();
    return SCPI_RES_OK;
}

static scpi_result_t My_CoreTstQ(scpi_t* context)
{

    SCPI_ResultInt32(context, 0);

    return SCPI_RES_OK;
}


static scpi_result_t SCPI_RouteClose(scpi_t* context)
{
    scpi_channel_value_t array[MAXROW * MAXCOL];
    size_t arr_index = 0;

	if(!SCPI_ChannelList(context, array, &arr_index, MAXROW, MAXCOL, MAXDIM))
	{
		return SCPI_RES_ERR;
	}


	if(array[arr_index -1].row >= MODULE_RELAY_INDEX)
	{
		if(board.module.detected)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_MODULE_NOT_MOUNTED);
			return SCPI_RES_ERR;
		}
	}

	SCPI_CreateSPICommands(array, arr_index, CLOSE);
	SCPI_MatrixStatusUpdate(array, arr_index, CLOSE);
	SCPI_SendSPICommand();

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteCloseQ(scpi_t* context)
{
	scpi_channel_value_t array[MAXROW * MAXCOL];
    size_t arr_index = 0;
    uint8_t state = 0;

    if(!SCPI_ChannelList(context, array, &arr_index, MAXROW, MAXCOL, MAXDIM))
    {
		return SCPI_RES_ERR;
	}

	if(array[arr_index - 1].row >= MODULE_RELAY_INDEX)
	{
		if(board.module.detected)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_MODULE_NOT_MOUNTED);
			return SCPI_RES_ERR;
		}
	}

    for(uint16_t i = 0; i < arr_index; i++)
    {
    	(CLOSE == matrix.relays[i].state) ? (state = TRUE) : (state = FALSE);
    	SCPI_ResultBool(context, state);
    }
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteOpen(scpi_t* context)
{
    scpi_channel_value_t array[MAXROW * MAXCOL];
    size_t arr_index = 0;

	if(!SCPI_ChannelList(context, array, &arr_index, MAXROW, MAXCOL, MAXDIM))
	{
		return SCPI_RES_ERR;
	}

	if(array[arr_index - 1].row >= MODULE_RELAY_INDEX)
	{
		if(board.module.detected)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_MODULE_NOT_MOUNTED);
			return SCPI_RES_ERR;
		}
	}

	SCPI_CreateSPICommands(array, arr_index, OPEN);
	SCPI_MatrixStatusUpdate(array, arr_index, OPEN);
	SCPI_SendSPICommand();

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteOpenAll(scpi_t* context)
{
    scpi_channel_value_t array[MAXROW * MAXCOL];
    size_t arr_index = 0;

	for (uint8_t i = 0; i < MAXROW; i++)
	{
		array[i].col = 0;
		array[i].row = i;
	}

	if(board.module.detected)
	{
		arr_index = MAXROW - 1;
	}
	else
	{
		arr_index = MAXROW/2 - 1;
	}

	SCPI_CreateSPICommands(array, arr_index, OPEN);
	SCPI_MatrixStatusUpdate(array, arr_index, OPEN);
	SCPI_SendSPICommand();

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteOpenQ(scpi_t* context)
{
	scpi_channel_value_t array[MAXROW * MAXCOL];
    size_t arr_index = 0;
    uint8_t state = 0;

    if(!SCPI_ChannelList(context, array, &arr_index, MAXROW, MAXCOL, MAXDIM))
    {
		return SCPI_RES_ERR;
	}

	if(array[arr_index - 1].row >= MODULE_RELAY_INDEX)
	{
		if(board.module.detected)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_MODULE_NOT_MOUNTED);
			return SCPI_RES_ERR;
		}
	}

    for(uint16_t i = 0; i < arr_index; i++)
    {
    	(OPEN == matrix.relays[i].state) ? (state = TRUE) : (state = FALSE);
    	SCPI_ResultBool(context, state);
    }
    return SCPI_RES_OK;
}

scpi_choice_def_t DHCP_state_select[] =
{
    {"OFF", 0},
    {"ON", 1},
	{"0", 0},
	{"1", 1},
    SCPI_CHOICE_LIST_END
};


scpi_choice_def_t LAN_state_select[] =
{
    {"CURRent", 0},
    {"STATic", 1},
    SCPI_CHOICE_LIST_END
};

static scpi_result_t SCPI_SystemCommunicationLanGateway(scpi_t* context) //done
{
	uint8_t gateway_str[16] = {0};
	uint8_t gateway_numb[4] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(!SCPI_ParamCopyText(context,gateway_str, 16, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToIP4Array(gateway_str, gateway_numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.ip4_current.gateway[0] = gateway_numb[0];
		board.ip4_current.gateway[1] = gateway_numb[1];
		board.ip4_current.gateway[2] = gateway_numb[2];
		board.ip4_current.gateway[3] = gateway_numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanGatewayQ(scpi_t* context) //done
{
	int32_t value;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.ip4_current.gateway[0], board.ip4_current.gateway[1],
									board.ip4_current.gateway[2], board.ip4_current.gateway[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.ip4_static.gateway[0], board.ip4_static.gateway[1],
									board.ip4_static.gateway[2], board.ip4_static.gateway[3]);
	}
	SCPI_ResultMnemonic(context, str);
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanHostname(scpi_t* context)
{
	int8_t hostname[NET_HOSTNAME] = {0};
	size_t length = 0;

	if(!SCPI_ParamCopyText(context, hostname, NET_HOSTNAME, &length, TRUE))
	{
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanHostnameQ(scpi_t* context)
{
	int32_t value;
	uint8_t str[255] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		SCPI_ResultMnemonic(context, (char*)board.ip4_current.hostname);
	}
	else if(STATIC == value)
	{
		SCPI_ResultMnemonic(context, (char*)board.ip4_static.hostname);
	}
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanIPAddress(scpi_t* context) //done
{
	uint8_t str[16] = {0};
	uint8_t numb[4] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(!SCPI_ParamCopyText(context,(char*)str, 16, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToIP4Array(str, numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.ip4_current.ip[0] = numb[0];
		board.ip4_current.ip[1] = numb[1];
		board.ip4_current.ip[2] = numb[2];
		board.ip4_current.ip[3] = numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanIPAddressQ(scpi_t* context)
{
	int32_t value;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.ip4_current.ip[0],board.ip4_current.ip[1], board.ip4_current.ip[2], board.ip4_current.ip[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.ip4_static.ip[0],board.ip4_static.ip[1], board.ip4_static.ip[2], board.ip4_static.ip[3]);
	}
	SCPI_ResultMnemonic(context, (char*)str);
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanMACQ(scpi_t* context)
{
	uint8_t str[18] = {0};
	if(!board.default_config)
	{
		sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", board.ip4_current.MAC[0], board.ip4_current.MAC[1],
														board.ip4_current.MAC[2], board.ip4_current.MAC[3],
														board.ip4_current.MAC[4], board.ip4_current.MAC[5]);
	}
	else
	{
		sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", board.ip4_static.MAC[0], board.ip4_static.MAC[1],
														board.ip4_static.MAC[2], board.ip4_static.MAC[3],
														board.ip4_static.MAC[4], board.ip4_static.MAC[5]);
	}

	SCPI_ResultMnemonic(context, (char*)str);
    return SCPI_RES_OK;
}



static scpi_result_t SCPI_SystemCommunicationLanSmask(scpi_t* context)
{
	uint8_t str[16] = {0};
	uint8_t numb[4] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(!SCPI_ParamCopyText(context,(char*)str, 16, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToIP4Array(str, numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.ip4_current.netmask[0] = numb[0];
		board.ip4_current.netmask[1] = numb[1];
		board.ip4_current.netmask[2] = numb[2];
		board.ip4_current.netmask[3] = numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}


static scpi_result_t SCPI_SystemCommunicationLanSmaskQ(scpi_t* context)
{
	int32_t value;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.ip4_current.netmask[0], board.ip4_current.netmask[1],
									board.ip4_current.netmask[2], board.ip4_current.netmask[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.ip4_static.netmask[0], board.ip4_static.netmask[1],
									board.ip4_static.netmask[2], board.ip4_static.netmask[3]);
	}
	SCPI_ResultMnemonic(context, (char*)str);
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanUpdate(scpi_t* context)
{
	SPI_FLASH_BoardUpdate();
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanPort(scpi_t* context)
{
	uint32_t port = 0;

	if(!SCPI_ParamUInt32(context, &port, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(port > ETH_PORT_VAL)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_TOO_MANY_DIGITS);
		return SCPI_RES_ERR;
	}

	board.ip4_current.port = (uint16_t)port;

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanPortQ(scpi_t* context)
{
	SCPI_ResultUInt16(context, board.ip4_current.port);
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemServiceLanMAC(scpi_t* context)
{
	uint8_t str[18] = {0};
	uint8_t numb[6] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(board.security.on)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SERVICE_MODE_SECURE);
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamCopyText(context,(char*)str, 18, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToMACArray(str, numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.ip4_current.MAC[0] = numb[0];
		board.ip4_current.MAC[1] = numb[1];
		board.ip4_current.MAC[2] = numb[2];
		board.ip4_current.MAC[3] = numb[3];
		board.ip4_current.MAC[4] = numb[4];
		board.ip4_current.MAC[5] = numb[5];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemServiceDefault(scpi_t* context)
{
	if(board.security.on)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SERVICE_MODE_SECURE);
		return SCPI_RES_ERR;
	}

	SPI_FLASH_BoardDefault(TRUE);
    return SCPI_RES_OK;
}

scpi_choice_def_t security_state_select[] =
{
    {"OFF", 0},
    {"ON", 1},
    SCPI_CHOICE_LIST_END
};

static scpi_result_t SCPI_SystemSecureState(scpi_t* context)
{
	int32_t state;
	int8_t password_read[PASSWORD_LENGTH];
	size_t length = 0;
	int8_t* password_reference = board.security.password;

	if(!SCPI_ParamChoice(context, security_state_select, &state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamCopyText(context, (char*)password_read, PASSWORD_LENGTH, &length, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!strcmp((const char*)password_read, (const char*)password_reference))
	{
		board.security.on = SECURITY_OFF;
		return SCPI_RES_ERR;
	}
	else
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SERVICE_INVALID_PASSWORD);
		return SCPI_RES_ERR;
	}

	return SCPI_RES_ERR;
}

static scpi_result_t SCPI_SystemSecureStateQ(scpi_t* context)
{
	SCPI_ResultBool(context, board.security.on);
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_TSQ(scpi_t* context)
{
	uint32_t timeout = 1000;
	uint8_t tx[3] = { 0x00, 0xFF, 0xFF};
	HAL_GPIO_WritePin(RELAY1_nCS0_GPIO_Port, RELAY1_nCS0_Pin, OFF);
	HAL_SPI_Transmit(&hspi5, &tx, 3, timeout);
	HAL_GPIO_WritePin(RELAY1_nCS0_GPIO_Port, RELAY1_nCS0_Pin, ON);
	return SCPI_RES_OK;
}



const scpi_command_t scpi_commands[] = {
    /* IEEE Mandated Commands (SCPI std V1999.0 4.1.1) */
    { .pattern = "*CLS", .callback = SCPI_CoreCls,},
    { .pattern = "*ESE", .callback = SCPI_CoreEse,},
    { .pattern = "*ESE?", .callback = SCPI_CoreEseQ,},
    { .pattern = "*ESR?", .callback = SCPI_CoreEsrQ,},
    { .pattern = "*IDN?", .callback = SCPI_CoreIdnQ,},
    { .pattern = "*OPC", .callback = SCPI_CoreOpc,},
    { .pattern = "*OPC?", .callback = SCPI_CoreOpcQ,},
    { .pattern = "*RST", .callback = SCPI_CoreRst,},
    { .pattern = "*SRE", .callback = SCPI_CoreSre,},
    { .pattern = "*SRE?", .callback = SCPI_CoreSreQ,},
    { .pattern = "*STB?", .callback = SCPI_CoreStbQ,},
    { .pattern = "*TST?", .callback = My_CoreTstQ,},
    { .pattern = "*WAI", .callback = SCPI_CoreWai,},

    /* Required SCPI commands (SCPI std V1999.0 4.2.1) */
    {.pattern = "SYSTem:ERRor[:NEXT]?", .callback = SCPI_SystemErrorNextQ,},
    {.pattern = "SYSTem:ERRor:COUNt?", .callback = SCPI_SystemErrorCountQ,},
    {.pattern = "SYSTem:VERSion?", .callback = SCPI_SystemVersionQ,},

    /* {.pattern = "STATus:OPERation?", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:EVENt?", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:CONDition?", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:ENABle", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:ENABle?", .callback = scpi_stub_callback,}, */

    {.pattern = "STATus:QUEStionable[:EVENt]?", .callback = SCPI_StatusQuestionableEventQ,},
    /* {.pattern = "STATus:QUEStionable:CONDition?", .callback = scpi_stub_callback,}, */
    {.pattern = "STATus:QUEStionable:ENABle", .callback = SCPI_StatusQuestionableEnable,},
    {.pattern = "STATus:QUEStionable:ENABle?", .callback = SCPI_StatusQuestionableEnableQ,},
    {.pattern = "STATus:PRESet", .callback = SCPI_StatusPreset,},

	// Relay card commands
	{.pattern = "[ROUTe]:CLOSe", .callback = SCPI_RouteClose,}, // <channel_list>
	{.pattern = "[ROUTe]:CLOSe?", .callback = SCPI_RouteCloseQ,}, // <channel_list>
	{.pattern = "[ROUTe]:OPEN", .callback = SCPI_RouteOpen,}, // <channel_list>
	{.pattern = "[ROUTe]:OPEN:ALL", .callback = SCPI_RouteOpenAll,},
	{.pattern = "[ROUTe]:OPEN?", .callback = SCPI_RouteOpenQ,}, // <channel_list>

	// Relay card system commands
	{.pattern = "SYSTem:COMMunication:LAN:GATeway", .callback = SCPI_SystemCommunicationLanGateway,}, // "<address>"
	{.pattern = "SYSTem:COMMunication:LAN:GATeway?", .callback = SCPI_SystemCommunicationLanGatewayQ,}, // [{CURRent|STATic}]
	{.pattern = "SYSTem:COMMunication:LAN:HOSTname", .callback = SCPI_SystemCommunicationLanHostname,}, // "<name>"
	{.pattern = "SYSTem:COMMunication:LAN:HOSTname?", .callback = SCPI_SystemCommunicationLanHostnameQ,}, // [{CURRent|STATic}]
	{.pattern = "SYSTem:COMMunication:LAN:IPADdress", .callback = SCPI_SystemCommunicationLanIPAddress,}, // "<address>"
	{.pattern = "SYSTem:COMMunication:LAN:IPADdress?", .callback = SCPI_SystemCommunicationLanIPAddressQ,}, // [{CURRent|STATic}]
	{.pattern = "SYSTem:COMMunication:LAN:MAC?", .callback = SCPI_SystemCommunicationLanMACQ,},
	{.pattern = "SYSTem:COMMunication:LAN:SMASk", .callback = SCPI_SystemCommunicationLanSmask,}, // "<mask>"
	{.pattern = "SYSTem:COMMunication:LAN:SMASk?", .callback = SCPI_SystemCommunicationLanSmaskQ,}, // [{CURRent|STATic}]
	{.pattern = "SYSTem:COMMunication:LAN:UPDate", .callback = SCPI_SystemCommunicationLanUpdate,},
	{.pattern = "SYSTem:COMMunication:LAN:PORT", .callback = SCPI_SystemCommunicationLanPort,}, // <port number>
	{.pattern = "SYSTem:COMMunication:LAN:PORT?", .callback = SCPI_SystemCommunicationLanPortQ,},

	// Relay card  service commands
	{.pattern = "SYSTem:SERVice:LAN:MAC", .callback = SCPI_SystemServiceLanMAC,}, // "<MAC address, IP4>"
	{.pattern = "SYSTem:SERVice:DEFAult", .callback = SCPI_SystemServiceDefault,},
	{.pattern = "SYSTem:SECure:STATe", .callback = SCPI_SystemSecureState,}, // {ON|1|OFF|0}[,<code>]
	{.pattern = "SYSTem:SECure:STATe?", .callback = SCPI_SystemSecureStateQ,},


	{.pattern = "TS?", .callback = SCPI_TSQ,},


    SCPI_CMD_LIST_END
};

scpi_interface_t scpi_interface = {
    .error = SCPI_Error,
    .write = SCPI_Write,
    .control = SCPI_Control,
    .flush = SCPI_Flush,
    .reset = SCPI_Reset,
};

char scpi_input_buffer[SCPI_INPUT_BUFFER_LENGTH];
scpi_error_t scpi_error_queue_data[SCPI_ERROR_QUEUE_SIZE];

scpi_t scpi_context;

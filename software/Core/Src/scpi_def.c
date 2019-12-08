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
#include "scpi_def.h"
#include "main.h"
#include "lwip/tcpip.h"

#include "spi_flash.h"


extern struct echo_state *es_scpi;
extern struct tcp_pcb *tcp_echoserver_pcb;


size_t SCPI_Write(scpi_t* context, const char * data, size_t len)
{
    (void) context;
    //err_t wr_err = ERR_OK;
    uint16_t size =0;
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

    fprintf(stderr, "**Reset\r\n");
    return SCPI_RES_OK;
}

static scpi_result_t My_CoreTstQ(scpi_t* context)
{

    SCPI_ResultInt32(context, 0);

    return SCPI_RES_OK;
}


static scpi_result_t SCPI_RouteClose(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteCloseQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteOpen(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteOpenQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_RouteScan(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanDHCP(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanDHCPQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanGateway(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanGatewayQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanHostname(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanHostnameQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanIPAddress(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanIPAddressQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanMACQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanSmask(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanSmaskQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanUpdate(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanPort(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemCommunicationLanPortQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemServiceLanMAC(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemServiceDefault(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemSecureState(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_SystemSecureStateQ(scpi_t* context)
{

    return SCPI_RES_OK;
}

static scpi_result_t SCPI_TSQ(scpi_t* context)
{
	uint8_t* rx_data;
	uint8_t tx_data = 0x01;
	rx_data = (uint8_t)malloc(3*sizeof(uint8_t));

	SPI_FLASH_EraseAll(0);
	SPI_FLASH_Read(0x00000000, rx_data, 15, 0);
	//rx_data = SPI_FLASH_GetManufacturerID(0);

	SCPI_ResultArrayUInt8(context, rx_data, 15, SCPI_FORMAT_ASCII);
	//SCPI_ResultBool(context, SPI_FLASH_IsProtected(0));
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
	{.pattern = "[ROUTe]:OPEN?", .callback = SCPI_RouteOpenQ,}, // <channel_list>
	{.pattern = "[ROUTe]:SCAN", .callback = SCPI_RouteScan,}, // <channel_list>

	// Relay card system commands
	{.pattern = "SYSTem:COMMunication:LAN:DHCP", .callback = SCPI_SystemCommunicationLanDHCP,}, // {ON|1|OFF|0}
	{.pattern = "SYSTem:COMMunication:LAN:DHCP?", .callback = SCPI_SystemCommunicationLanDHCPQ,},
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

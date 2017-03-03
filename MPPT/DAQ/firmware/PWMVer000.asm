;/////////////////////////////////////////////////////////////////////////////////
;// Code Generator: BoostC Compiler - http://www.sourceboost.com
;// Version       : 7.20
;// License Type  : Pro License
;// Limitations   : PIC18 max code size:Unlimited, max RAM banks:Unlimited
;/////////////////////////////////////////////////////////////////////////////////

	include "P18F14K50.inc"
__HEAPSTART                      EQU	0x000002A8 ; Start address of heap 
__HEAPEND                        EQU	0x000002FF ; End address of heap 
memcpy8_00000_arg_dst            EQU	0x00000231 ; bytes:2
memcpy8_00000_arg_src            EQU	0x00000233 ; bytes:2
memcpy8_00000_arg_len            EQU	0x00000235 ; bytes:1
CompTempVarRet410                EQU	0x0000023A ; bytes:2
memcpy8_00000_1_dst2             EQU	0x00000236 ; bytes:2
memcpy8_00000_1_src2             EQU	0x00000238 ; bytes:2
CompTempVar411                   EQU	0x0000023A ; bytes:1
gbl_status                       EQU	0x00000FD8 ; bytes:1
gbl_prodl                        EQU	0x00000FF3 ; bytes:1
gbl_prodh                        EQU	0x00000FF4 ; bytes:1
__mul_32_3_00007_arg_a           EQU	0x000001F9 ; bytes:4
__mul_32_3_00007_arg_b           EQU	0x00000220 ; bytes:4
CompTempVarRet426                EQU	0x00000225 ; bytes:4
gbl_14_LSR                       EQU	0x000000FC ; bytes:4
gbl_float_detect_tininess        EQU	0x0000005F ; bytes:1
gbl_float_rounding_mode          EQU	0x000001D7 ; bytes:1
gbl_float_exception_flags        EQU	0x000001D8 ; bytes:1
gbl_15_gbl_aSig                  EQU	0x000001AE ; bytes:4
gbl_15_gbl_bSig                  EQU	0x000001B2 ; bytes:4
gbl_15_gbl_zSig                  EQU	0x000001B6 ; bytes:4
gbl_15_gbl_aExp                  EQU	0x000001D9 ; bytes:1
gbl_15_gbl_bExp                  EQU	0x000001DA ; bytes:1
gbl_15_gbl_zExp                  EQU	0x000001C9 ; bytes:2
gbl_15_gbl_aSign                 EQU	0x000001DB ; bytes:1
gbl_15_gbl_bSign                 EQU	0x000001DC ; bytes:1
gbl_15_gbl_zSign                 EQU	0x000001DD ; bytes:1
gbl_15_gbl_zSigZero              EQU	0x000001DE ; bytes:1
gbl_15_gbl_ret                   EQU	0x000001BA ; bytes:4
gbl_uep0                         EQU	0x00000F53 ; bytes:1
gbl_uep1                         EQU	0x00000F54 ; bytes:1
gbl_uep2                         EQU	0x00000F55 ; bytes:1
gbl_uep3                         EQU	0x00000F56 ; bytes:1
gbl_uep4                         EQU	0x00000F57 ; bytes:1
gbl_uep5                         EQU	0x00000F58 ; bytes:1
gbl_uep6                         EQU	0x00000F59 ; bytes:1
gbl_uep7                         EQU	0x00000F5A ; bytes:1
gbl_ueie                         EQU	0x00000F5B ; bytes:1
gbl_uaddr                        EQU	0x00000F5C ; bytes:1
gbl_ufrml                        EQU	0x00000F5D ; bytes:1
gbl_ufrmh                        EQU	0x00000F5E ; bytes:1
gbl_ueir                         EQU	0x00000F5F ; bytes:1
gbl_uie                          EQU	0x00000F60 ; bytes:1
gbl_ucfg                         EQU	0x00000F61 ; bytes:1
gbl_uir                          EQU	0x00000F62 ; bytes:1
gbl_ustat                        EQU	0x00000F63 ; bytes:1
gbl_ucon                         EQU	0x00000F64 ; bytes:1
gbl_srcon0                       EQU	0x00000F68 ; bytes:1
gbl_srcon1                       EQU	0x00000F69 ; bytes:1
gbl_cm2con0                      EQU	0x00000F6B ; bytes:1
gbl_cm2con1                      EQU	0x00000F6C ; bytes:1
gbl_cm1con0                      EQU	0x00000F6D ; bytes:1
gbl_sspmsk                       EQU	0x00000F6F ; bytes:1
gbl_slrcon                       EQU	0x00000F76 ; bytes:1
gbl_wpua                         EQU	0x00000F77 ; bytes:1
gbl_wpub                         EQU	0x00000F78 ; bytes:1
gbl_ioca                         EQU	0x00000F79 ; bytes:1
gbl_iocb                         EQU	0x00000F7A ; bytes:1
gbl_ansel                        EQU	0x00000F7E ; bytes:1
gbl_anselh                       EQU	0x00000F7F ; bytes:1
gbl_porta                        EQU	0x00000F80 ; bytes:1
gbl_portb                        EQU	0x00000F81 ; bytes:1
gbl_portc                        EQU	0x00000F82 ; bytes:1
gbl_lata                         EQU	0x00000F89 ; bytes:1
gbl_latb                         EQU	0x00000F8A ; bytes:1
gbl_latc                         EQU	0x00000F8B ; bytes:1
gbl_ddra                         EQU	0x00000F92 ; bytes:1
gbl_trisa                        EQU	0x00000F92 ; bytes:1
gbl_ddrb                         EQU	0x00000F93 ; bytes:1
gbl_trisb                        EQU	0x00000F93 ; bytes:1
gbl_ddrc                         EQU	0x00000F94 ; bytes:1
gbl_trisc                        EQU	0x00000F94 ; bytes:1
gbl_osctune                      EQU	0x00000F9B ; bytes:1
gbl_pie1                         EQU	0x00000F9D ; bytes:1
gbl_pir1                         EQU	0x00000F9E ; bytes:1
gbl_ipr1                         EQU	0x00000F9F ; bytes:1
gbl_pie2                         EQU	0x00000FA0 ; bytes:1
gbl_pir2                         EQU	0x00000FA1 ; bytes:1
gbl_ipr2                         EQU	0x00000FA2 ; bytes:1
gbl_eecon1                       EQU	0x00000FA6 ; bytes:1
gbl_eecon2                       EQU	0x00000FA7 ; bytes:1
gbl_eedata                       EQU	0x00000FA8 ; bytes:1
gbl_eeadr                        EQU	0x00000FA9 ; bytes:1
gbl_rcsta                        EQU	0x00000FAB ; bytes:1
gbl_txsta                        EQU	0x00000FAC ; bytes:1
gbl_txreg                        EQU	0x00000FAD ; bytes:1
gbl_rcreg                        EQU	0x00000FAE ; bytes:1
gbl_spbrg                        EQU	0x00000FAF ; bytes:1
gbl_spbrgh                       EQU	0x00000FB0 ; bytes:1
gbl_t3con                        EQU	0x00000FB1 ; bytes:1
gbl_tmr3l                        EQU	0x00000FB2 ; bytes:1
gbl_tmr3h                        EQU	0x00000FB3 ; bytes:1
gbl_eccp1as                      EQU	0x00000FB6 ; bytes:1
gbl_pwm1con                      EQU	0x00000FB7 ; bytes:1
gbl_baudcon                      EQU	0x00000FB8 ; bytes:1
gbl_baudctl                      EQU	0x00000FB8 ; bytes:1
gbl_pstrcon                      EQU	0x00000FB9 ; bytes:1
gbl_refcon0                      EQU	0x00000FBA ; bytes:1
gbl_vrefcon0                     EQU	0x00000FBA ; bytes:1
gbl_refcon1                      EQU	0x00000FBB ; bytes:1
gbl_vrefcon1                     EQU	0x00000FBB ; bytes:1
gbl_refcon2                      EQU	0x00000FBC ; bytes:1
gbl_vrefcon2                     EQU	0x00000FBC ; bytes:1
gbl_ccp1con                      EQU	0x00000FBD ; bytes:1
gbl_ccpr1                        EQU	0x00000FBE ; bytes:1
gbl_ccpr1l                       EQU	0x00000FBE ; bytes:1
gbl_ccpr1h                       EQU	0x00000FBF ; bytes:1
gbl_adcon2                       EQU	0x00000FC0 ; bytes:1
gbl_adcon1                       EQU	0x00000FC1 ; bytes:1
gbl_adcon0                       EQU	0x00000FC2 ; bytes:1
gbl_adres                        EQU	0x00000FC3 ; bytes:1
gbl_adresl                       EQU	0x00000FC3 ; bytes:1
gbl_adresh                       EQU	0x00000FC4 ; bytes:1
gbl_sspcon2                      EQU	0x00000FC5 ; bytes:1
gbl_sspcon1                      EQU	0x00000FC6 ; bytes:1
gbl_sspstat                      EQU	0x00000FC7 ; bytes:1
gbl_sspadd                       EQU	0x00000FC8 ; bytes:1
gbl_sspbuf                       EQU	0x00000FC9 ; bytes:1
gbl_t2con                        EQU	0x00000FCA ; bytes:1
gbl_pr2                          EQU	0x00000FCB ; bytes:1
gbl_tmr2                         EQU	0x00000FCC ; bytes:1
gbl_t1con                        EQU	0x00000FCD ; bytes:1
gbl_tmr1l                        EQU	0x00000FCE ; bytes:1
gbl_tmr1h                        EQU	0x00000FCF ; bytes:1
gbl_rcon                         EQU	0x00000FD0 ; bytes:1
gbl_wdtcon                       EQU	0x00000FD1 ; bytes:1
gbl_osccon2                      EQU	0x00000FD2 ; bytes:1
gbl_osccon                       EQU	0x00000FD3 ; bytes:1
gbl_t0con                        EQU	0x00000FD5 ; bytes:1
gbl_tmr0l                        EQU	0x00000FD6 ; bytes:1
gbl_tmr0h                        EQU	0x00000FD7 ; bytes:1
gbl_fsr2l                        EQU	0x00000FD9 ; bytes:1
gbl_fsr2h                        EQU	0x00000FDA ; bytes:1
gbl_plusw2                       EQU	0x00000FDB ; bytes:1
gbl_preinc2                      EQU	0x00000FDC ; bytes:1
gbl_postdec2                     EQU	0x00000FDD ; bytes:1
gbl_postinc2                     EQU	0x00000FDE ; bytes:1
gbl_indf2                        EQU	0x00000FDF ; bytes:1
gbl_bsr                          EQU	0x00000FE0 ; bytes:1
gbl_fsr1l                        EQU	0x00000FE1 ; bytes:1
gbl_fsr1h                        EQU	0x00000FE2 ; bytes:1
gbl_plusw1                       EQU	0x00000FE3 ; bytes:1
gbl_preinc1                      EQU	0x00000FE4 ; bytes:1
gbl_postdec1                     EQU	0x00000FE5 ; bytes:1
gbl_postinc1                     EQU	0x00000FE6 ; bytes:1
gbl_indf1                        EQU	0x00000FE7 ; bytes:1
gbl_wreg                         EQU	0x00000FE8 ; bytes:1
gbl_fsr0l                        EQU	0x00000FE9 ; bytes:1
gbl_fsr0h                        EQU	0x00000FEA ; bytes:1
gbl_plusw0                       EQU	0x00000FEB ; bytes:1
gbl_preinc0                      EQU	0x00000FEC ; bytes:1
gbl_postdec0                     EQU	0x00000FED ; bytes:1
gbl_postinc0                     EQU	0x00000FEE ; bytes:1
gbl_indf0                        EQU	0x00000FEF ; bytes:1
gbl_intcon3                      EQU	0x00000FF0 ; bytes:1
gbl_intcon2                      EQU	0x00000FF1 ; bytes:1
gbl_intcon                       EQU	0x00000FF2 ; bytes:1
gbl_prod                         EQU	0x00000FF3 ; bytes:1
gbl_tablat                       EQU	0x00000FF5 ; bytes:1
gbl_tblptr                       EQU	0x00000FF6 ; bytes:1
gbl_tblptrl                      EQU	0x00000FF6 ; bytes:1
gbl_tblptrh                      EQU	0x00000FF7 ; bytes:1
gbl_tblptru                      EQU	0x00000FF8 ; bytes:1
gbl_pc                           EQU	0x00000FF9 ; bytes:1
gbl_pcl                          EQU	0x00000FF9 ; bytes:1
gbl_pclath                       EQU	0x00000FFA ; bytes:1
gbl_pclatu                       EQU	0x00000FFB ; bytes:1
gbl_stkptr                       EQU	0x00000FFC ; bytes:1
gbl_tos                          EQU	0x00000FFD ; bytes:1
gbl_tosl                         EQU	0x00000FFD ; bytes:1
gbl_tosh                         EQU	0x00000FFE ; bytes:1
gbl_tosu                         EQU	0x00000FFF ; bytes:1
gbl_FCV_READINPUT                EQU	0x000001CB ; bytes:2
gbl_FCV_INSTRING                 EQU	0x000001C6 ; bytes:3
gbl_FCV_0df41_PWM1__ENABLED      EQU	0x000001DF ; bytes:1
gbl_MX_USBNAME                   EQU	0x0000012E ; bytes:40
gbl_MX_USBMFR                    EQU	0x00000100 ; bytes:46
gbl_MX_SERIAL                    EQU	0x000000E0 ; bytes:10
gbl_usb_state                    EQU	0x000001E0 ; bytes:1
gbl_usb_address                  EQU	0x000001E1 ; bytes:1
gbl_usb_sdp                      EQU	0x0000015F ; bytes:8
gbl_control_mode                 EQU	0x000001E2 ; bytes:1
gbl_bd0out                       EQU	0x00000200 ; bytes:4
gbl_bd0in                        EQU	0x00000204 ; bytes:4
gbl_bd1out                       EQU	0x00000208 ; bytes:4
gbl_bd1in                        EQU	0x0000020C ; bytes:4
gbl_bd2out                       EQU	0x00000210 ; bytes:4
gbl_bd2in                        EQU	0x00000214 ; bytes:4
gbl_bd3out                       EQU	0x00000218 ; bytes:4
gbl_bd3in                        EQU	0x0000021C ; bytes:4
gbl_buffer_0_out                 EQU	0x00000280 ; bytes:8
gbl_buffer_0_in                  EQU	0x00000288 ; bytes:8
gbl_buffer_2_in                  EQU	0x00000290 ; bytes:8
gbl_buffer_3_in                  EQU	0x000002A0 ; bytes:8
gbl_buffer_3_out                 EQU	0x00000298 ; bytes:8
gbl_ep_in_buffer_location        EQU	0x00000167 ; bytes:8
gbl_ep_out_buffer_location       EQU	0x0000016F ; bytes:8
gbl_ep_in_buffer_size            EQU	0x00000177 ; bytes:8
gbl_ep_out_buffer_size           EQU	0x0000017F ; bytes:8
CompGblVar60                     EQU	0x000001E3 ; bytes:1
CompGblVar61                     EQU	0x000001E4 ; bytes:1
CompGblVar62                     EQU	0x000001E5 ; bytes:1
CompGblVar63                     EQU	0x000001E6 ; bytes:1
CompGblVar64                     EQU	0x000001E7 ; bytes:1
gbl_delivery_bytes_to_send       EQU	0x000001CD ; bytes:2
gbl_delivery_bytes_max_send      EQU	0x000001CF ; bytes:2
gbl_delivery_bytes_sent          EQU	0x000001D1 ; bytes:2
gbl_delivery_ptr                 EQU	0x000001D3 ; bytes:2
gbl_delivery_buffer_size         EQU	0x000001E8 ; bytes:1
gbl_delivery_buffer              EQU	0x000001D5 ; bytes:2
gbl_usb_status                   EQU	0x000001E9 ; bytes:1
gbl_buffer_byte                  EQU	0x000001EA ; bytes:1
gbl_cdc_tx_buffer                EQU	0x00000060 ; bytes:64
gbl_cdc_tx_start                 EQU	0x000001EB ; bytes:1
gbl_cdc_tx_end                   EQU	0x000001EC ; bytes:1
gbl_cdc_rx_buffer                EQU	0x000000A0 ; bytes:64
gbl_cdc_rx_start                 EQU	0x000001ED ; bytes:1
gbl_cdc_rx_end                   EQU	0x000001EE ; bytes:1
gbl_class_data                   EQU	0x00000187 ; bytes:8
gbl_my_device_descriptor         EQU	0x00000048 ; bytes:18
gbl_my_config                    EQU	0x000000EA ; bytes:9
gbl_my_comm_interface            EQU	0x000000F3 ; bytes:9
gbl_my_header                    EQU	0x0000005A ; bytes:5
gbl_my_ACM                       EQU	0x000001BE ; bytes:4
gbl_my_union                     EQU	0x000001A4 ; bytes:5
gbl_my_call_mgt                  EQU	0x000001A9 ; bytes:5
gbl_my_notification_ep           EQU	0x0000018F ; bytes:7
gbl_my_data_interface            EQU	0x00000156 ; bytes:9
gbl_my_data_out_ep               EQU	0x00000196 ; bytes:7
gbl_my_data_in_ep                EQU	0x0000019D ; bytes:7
gbl_complete_serial_config_00000 EQU	0x00000005 ; bytes:67
gbl_string_00                    EQU	0x000001C2 ; bytes:4
gbl_CDC_USB_status               EQU	0x000001EF ; bytes:1
Wdt_Delay__00036_arg_delay       EQU	0x000001F8 ; bytes:1
Wdt_Delay__00036_1_i             EQU	0x000001F9 ; bytes:1
FCI_RIGHTS_00040_arg_sSrc        EQU	0x000001F0 ; bytes:2
FCI_RIGHTS_00040_arg_iSrc_len    EQU	0x000001F2 ; bytes:1
FCI_RIGHTS_00040_arg_iCount      EQU	0x000001F3 ; bytes:1
FCI_RIGHTS_00040_arg_sDst        EQU	0x000001F4 ; bytes:2
FCI_RIGHTS_00040_arg_iDst_len    EQU	0x000001F6 ; bytes:1
CompTempVarRet1866               EQU	0x000001F9 ; bytes:2
FCI_RIGHTS_00040_1_idx           EQU	0x000001F7 ; bytes:1
FCI_RIGHTS_00040_1_delta         EQU	0x000001F8 ; bytes:1
CompTempVar1868                  EQU	0x000001FB ; bytes:1
FCI_STRING_0004B_arg_String      EQU	0x000001F0 ; bytes:2
FCI_STRING_0004B_arg_MSZ_String  EQU	0x000001F2 ; bytes:1
CompTempVarRet1971               EQU	0x000001F9 ; bytes:4
FCI_STRING_0004B_1_bNegative     EQU	0x000001F3 ; bytes:1
FCI_STRING_0004B_1_idx           EQU	0x000001F4 ; bytes:1
FCI_STRING_0004B_1_RetVal        EQU	0x000001F5 ; bytes:4
CompTempVar1984                  EQU	0x000001FD ; bytes:1
CompTempVar1985                  EQU	0x000001FE ; bytes:1
CompTempVar1986                  EQU	0x000001FF ; bytes:1
CompTempVar1987                  EQU	0x00000224 ; bytes:1
CompTempVar1990                  EQU	0x000001F9 ; bytes:1
CompTempVar1991                  EQU	0x000001FA ; bytes:1
CompTempVar1992                  EQU	0x000001FB ; bytes:1
CompTempVar1993                  EQU	0x000001FC ; bytes:1
CompTempVar1995                  EQU	0x000001F9 ; bytes:1
CompTempVar1996                  EQU	0x000001FA ; bytes:1
CompTempVar1997                  EQU	0x000001FB ; bytes:1
CompTempVar1998                  EQU	0x000001FC ; bytes:1
FC_CAL_PWM_0004E_arg_period      EQU	0x000001F0 ; bytes:2
FC_CAL_PWM_0004E_arg_prescaler   EQU	0x000001F2 ; bytes:2
FC_CAL_PWM_00052_arg_duty        EQU	0x000001F2 ; bytes:2
FC_CAL_PWM_00052_1_nCCPxCONtemp  EQU	0x000001F4 ; bytes:1
CompTempVar2642                  EQU	0x000001F5 ; bytes:1
CompTempVar2643                  EQU	0x000001F6 ; bytes:1
CompTempVar2647                  EQU	0x000001F5 ; bytes:1
FCD_0df41__00058_arg_FCL_DUTY    EQU	0x000001F0 ; bytes:2
usb_send_d_0005F_arg_ep          EQU	0x00000236 ; bytes:1
usb_send_d_0005F_arg_data        EQU	0x00000237 ; bytes:2
usb_send_d_0005F_arg_send_count  EQU	0x00000239 ; bytes:1
usb_send_d_0005F_arg_first       EQU	0x0000023A ; bit:0
usb_send_d_0005F_1_count         EQU	0x0000023B ; bytes:1
usb_send_d_0005F_1_bdstat        EQU	0x0000023C ; bytes:2
usb_send_d_0005F_1_bdcount       EQU	0x0000023E ; bytes:2
usb_send_d_0005F_1_bdaddr        EQU	0x00000240 ; bytes:2
usb_send_d_0005F_1_buffer        EQU	0x00000242 ; bytes:2
CompTempVar2683                  EQU	0x00000244 ; bytes:1
CompTempVar2687                  EQU	0x00000244 ; bytes:1
CompTempVar2688                  EQU	0x00000244 ; bytes:1
CompTempVar2689                  EQU	0x00000244 ; bytes:1
CompTempVar2690                  EQU	0x00000244 ; bytes:1
CompTempVar2691                  EQU	0x00000244 ; bytes:1
CompTempVar2692                  EQU	0x00000244 ; bytes:1
CompTempVar2693                  EQU	0x00000244 ; bytes:1
CompTempVar2694                  EQU	0x00000244 ; bytes:1
CompTempVar2695                  EQU	0x00000244 ; bytes:1
CompTempVar2698                  EQU	0x00000244 ; bytes:1
CompTempVar2699                  EQU	0x00000245 ; bytes:1
CompTempVar2700                  EQU	0x00000244 ; bytes:1
usb_handle_00065_arg_data        EQU	0x0000022B ; bytes:2
usb_handle_00065_arg_count       EQU	0x0000022D ; bytes:2
usb_handle_00065_1_my_lc         EQU	0x0000022F ; bytes:2
usb_handle_00066_arg_sdp         EQU	0x0000022E ; bytes:8
usb_get_de_00067_arg_descr_00068 EQU	0x00000238 ; bytes:1
usb_get_de_00067_arg_descr_00069 EQU	0x00000239 ; bytes:1
usb_get_de_00067_arg_rtn_d_0006A EQU	0x0000023A ; bytes:2
usb_get_de_00067_arg_rtn_d_0006B EQU	0x0000023C ; bytes:2
usb_get_de_00067_1_descrip_0006C EQU	0x0000023E ; bytes:2
usb_get_de_00067_1_descrip_0006D EQU	0x00000240 ; bytes:2
CompTempVar2712                  EQU	0x00000242 ; bytes:1
CompTempVar2713                  EQU	0x00000242 ; bytes:1
CompTempVar2714                  EQU	0x00000242 ; bytes:1
CompTempVar2715                  EQU	0x00000242 ; bytes:1
CompTempVar2716                  EQU	0x00000242 ; bytes:1
CompTempVar2717                  EQU	0x00000242 ; bytes:1
CompTempVar2718                  EQU	0x00000242 ; bytes:1
usb_ep_dat_0006E_arg_end_point   EQU	0x0000022F ; bytes:1
usb_ep_dat_0006E_arg_buffer      EQU	0x00000230 ; bytes:2
usb_ep_dat_0006E_arg_byte_count  EQU	0x00000232 ; bytes:2
usb_ep_dat_0006E_1_cdc_rx_next   EQU	0x00000234 ; bytes:1
usb_ep_dat_0006E_2_count         EQU	0x00000235 ; bytes:1
CompTempVar2721                  EQU	0x00000236 ; bytes:1
CompTempVar2722                  EQU	0x00000237 ; bytes:1
usb_ep_dat_0006F_arg_end_point   EQU	0x0000022C ; bytes:1
usb_ep_dat_0006F_arg_byte_count  EQU	0x0000022D ; bytes:2
usb_SOF_ca_0005D_arg_frame       EQU	0x00000229 ; bytes:2
usb_send_d_00061_1_count         EQU	0x0000023A ; bytes:1
CompTempVar2705                  EQU	0x0000023B ; bytes:1
usb_send_o_00073_arg_data        EQU	0x00000238 ; bytes:1
usb_handle_00075_arg_sdp         EQU	0x0000022E ; bytes:8
usb_handle_00075_1_descrip_00076 EQU	0x00000236 ; bytes:1
usb_handle_00075_1_descrip_00077 EQU	0x00000237 ; bytes:1
usb_handle_0005A_1_end_point     EQU	0x00000229 ; bytes:1
usb_handle_0005A_1_pid           EQU	0x0000022A ; bytes:1
CompTempVar2651                  EQU	0x0000022B ; bytes:1
CompTempVar2654                  EQU	0x0000022B ; bytes:1
CompTempVar2655                  EQU	0x0000022C ; bytes:1
CompTempVar2657                  EQU	0x0000022D ; bytes:1
usb_handle_0005A_88_count        EQU	0x0000022B ; bytes:1
usb_handle_0005A_97_bdstat       EQU	0x0000022B ; bytes:2
usb_handle_0005A_97_bdcount      EQU	0x0000022D ; bytes:2
CompTempVar2663                  EQU	0x0000022F ; bytes:1
CompTempVar2664                  EQU	0x0000022F ; bytes:1
CompTempVar2665                  EQU	0x0000022F ; bytes:1
CompTempVar2666                  EQU	0x0000022F ; bytes:1
CompTempVar2667                  EQU	0x0000022F ; bytes:1
CompTempVar2668                  EQU	0x0000022F ; bytes:1
CompTempVar2675                  EQU	0x00000234 ; bytes:1
CompTempVar2678                  EQU	0x0000022F ; bytes:1
CompTempVar2680                  EQU	0x00000230 ; bytes:2
usb_cdc_ha_00070_1_cdc_tx_next   EQU	0x0000022F ; bytes:1
usb_cdc_ha_00070_1_count         EQU	0x00000230 ; bytes:1
usb_cdc_ha_00070_1_buffer_size   EQU	0x00000231 ; bytes:2
usb_cdc_ha_00070_1_buffer        EQU	0x00000233 ; bytes:2
usb_cdc_ha_00070_1_bd            EQU	0x00000235 ; bytes:2
usb_cdc_ha_00070_1_store_gie     EQU	0x00000237 ; bit:0
CompTempVar2728                  EQU	0x00000238 ; bytes:1
CompTempVar2729                  EQU	0x00000239 ; bytes:1
CompTempVar2730                  EQU	0x00000238 ; bytes:1
CompTempVarRet2736               EQU	0x000001F8 ; bytes:1
usb_cdc_se_0007C_1_my_lc         EQU	0x000001F3 ; bytes:2
CompTempVar2746                  EQU	0x000001F5 ; bytes:3
usb_ep_get_0007D_arg_length      EQU	0x000001F8 ; bytes:1
usb_ep_get_0007D_arg_buffer      EQU	0x000001F9 ; bytes:2
usb_ep_get_0007D_1_count         EQU	0x000001FB ; bytes:1
CompTempVar2749                  EQU	0x000001FC ; bytes:1
CompTempVar2750                  EQU	0x000001FD ; bytes:1
FCD_056e1__00080_arg_FCR_RETVAL  EQU	0x000001F0 ; bytes:2
FCD_056e1__00080_arg_FCRsz_00081 EQU	0x000001F2 ; bytes:2
FCD_056e1__00080_arg_FCL_T_00082 EQU	0x000001F4 ; bytes:1
FCD_056e1__00080_arg_FCL_LENGTH  EQU	0x000001F5 ; bytes:1
FCD_056e1__00080_1_FCL_WAI_00083 EQU	0x000001F6 ; bytes:1
FCD_056e1__00080_1_Rx_Length     EQU	0x000001F7 ; bytes:1
CompTempVarRet2765               EQU	0x000001F3 ; bytes:1
FCD_056e1__00088_1_FCL_DEL_00089 EQU	0x000001F0 ; bytes:2
FCD_056e1__00088_1_FCR_RETVAL    EQU	0x000001F2 ; bytes:1
delay_ms_00000_arg_del           EQU	0x000001FA ; bytes:1
usb_send_e_00060_1___retpointvar EQU	0x00000238 ; bytes:1
usb_send_o_00073_1___retpointvar EQU	0x00000239 ; bytes:1
Int1Context                      EQU	0x00000001 ; bytes:4
	ORG 0x00000000
	GOTO	_startup
	ORG 0x00000008
	GOTO	interrupt
	ORG 0x0000000C
delay_ms_00000
; { delay_ms ; function begin
	MOVF delay_ms_00000_arg_del, F, 1
	NOP
	BNZ	label1
	RETURN
label1
	MOVLW 0xF9
label2
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	ADDLW 0xFF
	BTFSS STATUS,Z
	BRA	label2
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	DECFSZ delay_ms_00000_arg_del, F, 1
	BRA	label1
	RETURN
; } delay_ms function end

	ORG 0x00000044
usb_send_d_00061
; { usb_send_data_chunk ; function begin
	MOVLB 0x02
	CLRF usb_send_d_00061_1_count, 1
label3
	MOVLB 0x01
	MOVF gbl_delivery_buffer_size, W, 1
	MOVLB 0x02
	CPFSLT usb_send_d_00061_1_count, 1
	BRA	label6
	MOVLB 0x01
	MOVF gbl_delivery_bytes_to_send+D'1', W, 1
	SUBWF gbl_delivery_bytes_sent+D'1', W, 1
	BNZ	label4
	MOVF gbl_delivery_bytes_to_send, W, 1
	SUBWF gbl_delivery_bytes_sent, W, 1
label4
	BC	label6
	MOVF gbl_delivery_bytes_max_send+D'1', W, 1
	SUBWF gbl_delivery_bytes_sent+D'1', W, 1
	BNZ	label5
	MOVF gbl_delivery_bytes_max_send, W, 1
	SUBWF gbl_delivery_bytes_sent, W, 1
label5
	BC	label6
	MOVF gbl_delivery_ptr+D'1', W, 1
	MOVWF FSR0H
	MOVF gbl_delivery_ptr, W, 1
	MOVWF FSR0L
	MOVF INDF0, W
	MOVLB 0x02
	MOVWF CompTempVar2705, 1
	MOVLB 0x01
	MOVF gbl_delivery_buffer+D'1', W, 1
	MOVWF FSR0H
	MOVF gbl_delivery_buffer, W, 1
	MOVLB 0x02
	ADDWF usb_send_d_00061_1_count, W, 1
	MOVWF FSR0L
	MOVF CompTempVar2705, W, 1
	MOVWF INDF0
	MOVLB 0x01
	INFSNZ gbl_delivery_ptr, F, 1
	INCF gbl_delivery_ptr+D'1', F, 1
	INFSNZ gbl_delivery_bytes_sent, F, 1
	INCF gbl_delivery_bytes_sent+D'1', F, 1
	MOVLB 0x02
	INCF usb_send_d_00061_1_count, F, 1
	BRA	label3
label6
	MOVLB 0x01
	MOVF gbl_delivery_buffer_size, W, 1
	MOVLB 0x02
	CPFSLT usb_send_d_00061_1_count, 1
	BRA	label9
	MOVLB 0x01
	MOVF gbl_delivery_bytes_max_send, W, 1
	CPFSEQ gbl_delivery_bytes_sent, 1
	BRA	label7
	MOVF gbl_delivery_bytes_max_send+D'1', W, 1
	CPFSEQ gbl_delivery_bytes_sent+D'1', 1
	BRA	label7
	BRA	label8
label7
	MOVF gbl_delivery_bytes_to_send, W, 1
	CPFSEQ gbl_delivery_bytes_sent, 1
	BRA	label9
	MOVF gbl_delivery_bytes_to_send+D'1', W, 1
	CPFSEQ gbl_delivery_bytes_sent+D'1', 1
	BRA	label9
label8
	MOVLW 0x05
	MOVWF gbl_control_mode, 1
label9
	MOVLB 0x02
	MOVF usb_send_d_00061_1_count, W, 1
	MOVWF gbl_bd0in+D'1', 1
	MOVLW HIGH(gbl_buffer_0_in+D'0')
	MOVWF gbl_bd0in+D'3', 1
	MOVLW LOW(gbl_buffer_0_in+D'0')
	MOVWF gbl_bd0in+D'2', 1
	BTFSS gbl_bd0in,6, 1
	BRA	label10
	BCF gbl_bd0in,6, 1
	BRA	label11
label10
	BSF gbl_bd0in,6, 1
label11
	BCF gbl_bd0in,5, 1
	BCF gbl_bd0in,4, 1
	BSF gbl_bd0in,3, 1
	BCF gbl_bd0in,2, 1
	BCF gbl_bd0in,1, 1
	BCF gbl_bd0in,0, 1
	BSF gbl_bd0in,7, 1
	RETURN
; } usb_send_data_chunk function end

	ORG 0x000000EE
usb_stall__00062
; { usb_stall_ep0 ; function begin
	MOVLB 0x02
	BSF gbl_bd0in,2, 1
	BSF gbl_bd0in,7, 1
	BSF gbl_bd0out,2, 1
	BSF gbl_bd0out,7, 1
	RETURN
; } usb_stall_ep0 function end

	ORG 0x000000FA
usb_send_o_00073
; { usb_send_one_byte ; function begin
	MOVWF usb_send_o_00073_1___retpointvar, 1
	MOVLW 0x08
	MOVLB 0x01
	MOVWF gbl_delivery_buffer_size, 1
	CLRF gbl_delivery_bytes_sent, 1
	CLRF gbl_delivery_bytes_sent+D'1', 1
	MOVLW 0x01
	MOVWF gbl_delivery_bytes_to_send, 1
	CLRF gbl_delivery_bytes_to_send+D'1', 1
	CLRF gbl_delivery_bytes_max_send, 1
	CLRF gbl_delivery_bytes_max_send+D'1', 1
	MOVLB 0x02
	MOVF usb_send_o_00073_arg_data, W, 1
	MOVLB 0x01
	MOVWF gbl_buffer_byte, 1
	MOVLW HIGH(gbl_buffer_byte+D'0')
	MOVWF gbl_delivery_ptr+D'1', 1
	MOVLW LOW(gbl_buffer_byte+D'0')
	MOVWF gbl_delivery_ptr, 1
	MOVLW HIGH(gbl_buffer_0_in+D'0')
	MOVWF gbl_delivery_buffer+D'1', 1
	MOVLW LOW(gbl_buffer_0_in+D'0')
	MOVWF gbl_delivery_buffer, 1
	MOVLB 0x02
	BCF gbl_bd0in,6, 1
	CALL usb_send_d_00061
	BRA	label12
; AVOID CODE PAGE BOUNDARY BEGIN - page size:256 words
	ORG	0x0132
label12
	MOVLW	HIGH( label13 )
	MOVWF PCLATH
	MOVF usb_send_o_00073_1___retpointvar, W, 1
	ADDWF PCL, F
; RET_TABLE_BEGIN
label13
; RET_TABLE_ENTRY
	GOTO	label58
; RET_TABLE_ENTRY
	GOTO	label60
; RET_TABLE_END
; AVOID CODE BOUNDARY END 
; } usb_send_one_byte function end

	ORG 0x00000142
usb_send_e_00060
; { usb_send_empty_data_pkt ; function begin
	MOVLB 0x02
	MOVWF usb_send_e_00060_1___retpointvar, 1
	MOVLW 0x08
	MOVLB 0x01
	MOVWF gbl_delivery_buffer_size, 1
	MOVLW HIGH(gbl_buffer_0_in+D'0')
	MOVWF gbl_delivery_buffer+D'1', 1
	MOVLW LOW(gbl_buffer_0_in+D'0')
	MOVWF gbl_delivery_buffer, 1
	CLRF gbl_delivery_bytes_sent, 1
	CLRF gbl_delivery_bytes_sent+D'1', 1
	CLRF gbl_delivery_bytes_to_send, 1
	CLRF gbl_delivery_bytes_to_send+D'1', 1
	CLRF gbl_delivery_bytes_max_send, 1
	CLRF gbl_delivery_bytes_max_send+D'1', 1
	CLRF gbl_delivery_ptr, 1
	CLRF gbl_delivery_ptr+D'1', 1
	MOVLB 0x02
	BCF gbl_bd0in,6, 1
	CALL usb_send_d_00061
	BRA	label14
; AVOID CODE PAGE BOUNDARY BEGIN - page size:256 words
	ORG	0x016E
label14
	MOVLW	HIGH( label15 )
	MOVWF PCLATH
	MOVF usb_send_e_00060_1___retpointvar, W, 1
	ADDWF PCL, F
; RET_TABLE_BEGIN
label15
; RET_TABLE_ENTRY
	GOTO	label69
; RET_TABLE_ENTRY
	GOTO	label68
; RET_TABLE_ENTRY
	GOTO	label54
; RET_TABLE_ENTRY
	GOTO	label56
; RET_TABLE_END
; AVOID CODE BOUNDARY END 
; } usb_send_empty_data_pkt function end

	ORG 0x00000186
usb_send_d_0005F
; { usb_send_data ; function begin
	MOVLB 0x01
	LFSR 0x00, gbl_ep_in_buffer_location
	MOVF FSR0L, W
	MOVLB 0x02
	MOVF usb_send_d_0005F_arg_ep, W, 1
	MOVWF CompTempVar2683, 1
	BCF STATUS,C
	RLCF CompTempVar2683, W, 1
	ADDWF FSR0L, F
	MOVF POSTINC0, W
	MOVWF usb_send_d_0005F_1_buffer, 1
	MOVF INDF0, W
	MOVWF usb_send_d_0005F_1_buffer+D'1', 1
	MOVF usb_send_d_0005F_arg_ep, F, 1
	BZ	label17
	DECF usb_send_d_0005F_arg_ep, W, 1
	BZ	label18
	MOVLW 0x02
	CPFSEQ usb_send_d_0005F_arg_ep, 1
	BRA	label16
	BRA	label19
label16
	MOVLW 0x03
	CPFSEQ usb_send_d_0005F_arg_ep, 1
	BRA	label21
	BRA	label20
label17
	MOVLW HIGH(gbl_bd0in+D'0')
	MOVWF usb_send_d_0005F_1_bdstat+D'1', 1
	MOVLW LOW(gbl_bd0in+D'0')
	MOVWF usb_send_d_0005F_1_bdstat, 1
	MOVLW HIGH(gbl_bd0in+D'1')
	MOVWF usb_send_d_0005F_1_bdcount+D'1', 1
	MOVLW LOW(gbl_bd0in+D'1')
	MOVWF usb_send_d_0005F_1_bdcount, 1
	MOVLW HIGH(gbl_bd0in+D'2')
	MOVWF usb_send_d_0005F_1_bdaddr+D'1', 1
	MOVLW LOW(gbl_bd0in+D'2')
	MOVWF usb_send_d_0005F_1_bdaddr, 1
	BRA	label21
label18
	MOVLW HIGH(gbl_bd1in+D'0')
	MOVWF CompTempVar2687, 1
	MOVLW LOW(gbl_bd1in+D'0')
	MOVWF usb_send_d_0005F_1_bdstat, 1
	MOVF CompTempVar2687, W, 1
	MOVWF usb_send_d_0005F_1_bdstat+D'1', 1
	MOVLW HIGH(gbl_bd1in+D'1')
	MOVWF CompTempVar2688, 1
	MOVLW LOW(gbl_bd1in+D'1')
	MOVWF usb_send_d_0005F_1_bdcount, 1
	MOVF CompTempVar2688, W, 1
	MOVWF usb_send_d_0005F_1_bdcount+D'1', 1
	MOVLW HIGH(gbl_bd1in+D'2')
	MOVWF CompTempVar2689, 1
	MOVLW LOW(gbl_bd1in+D'2')
	MOVWF usb_send_d_0005F_1_bdaddr, 1
	MOVF CompTempVar2689, W, 1
	MOVWF usb_send_d_0005F_1_bdaddr+D'1', 1
	BRA	label21
label19
	MOVLW HIGH(gbl_bd2in+D'0')
	MOVWF CompTempVar2690, 1
	MOVLW LOW(gbl_bd2in+D'0')
	MOVWF usb_send_d_0005F_1_bdstat, 1
	MOVF CompTempVar2690, W, 1
	MOVWF usb_send_d_0005F_1_bdstat+D'1', 1
	MOVLW HIGH(gbl_bd2in+D'1')
	MOVWF CompTempVar2691, 1
	MOVLW LOW(gbl_bd2in+D'1')
	MOVWF usb_send_d_0005F_1_bdcount, 1
	MOVF CompTempVar2691, W, 1
	MOVWF usb_send_d_0005F_1_bdcount+D'1', 1
	MOVLW HIGH(gbl_bd2in+D'2')
	MOVWF CompTempVar2692, 1
	MOVLW LOW(gbl_bd2in+D'2')
	MOVWF usb_send_d_0005F_1_bdaddr, 1
	MOVF CompTempVar2692, W, 1
	MOVWF usb_send_d_0005F_1_bdaddr+D'1', 1
	BRA	label21
label20
	MOVLW HIGH(gbl_bd3in+D'0')
	MOVWF CompTempVar2693, 1
	MOVLW LOW(gbl_bd3in+D'0')
	MOVWF usb_send_d_0005F_1_bdstat, 1
	MOVF CompTempVar2693, W, 1
	MOVWF usb_send_d_0005F_1_bdstat+D'1', 1
	MOVLW HIGH(gbl_bd3in+D'1')
	MOVWF CompTempVar2694, 1
	MOVLW LOW(gbl_bd3in+D'1')
	MOVWF usb_send_d_0005F_1_bdcount, 1
	MOVF CompTempVar2694, W, 1
	MOVWF usb_send_d_0005F_1_bdcount+D'1', 1
	MOVLW HIGH(gbl_bd3in+D'2')
	MOVWF CompTempVar2695, 1
	MOVLW LOW(gbl_bd3in+D'2')
	MOVWF usb_send_d_0005F_1_bdaddr, 1
	MOVF CompTempVar2695, W, 1
	MOVWF usb_send_d_0005F_1_bdaddr+D'1', 1
label21
	MOVF usb_send_d_0005F_1_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdstat, W, 1
	MOVWF FSR0L
	BTFSC INDF0,7
	RETURN
	CLRF usb_send_d_0005F_1_count, 1
label22
	MOVF usb_send_d_0005F_arg_send_count, W, 1
	CPFSLT usb_send_d_0005F_1_count, 1
	BRA	label23
	MOVF usb_send_d_0005F_arg_data+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_arg_data, W, 1
	MOVWF FSR0L
	MOVF usb_send_d_0005F_1_count, W, 1
	MOVWF CompTempVar2698, 1
	MOVF CompTempVar2698, W, 1
	ADDWF FSR0L, F
	MOVF INDF0, W
	MOVWF CompTempVar2699, 1
	MOVF usb_send_d_0005F_1_buffer+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_buffer, W, 1
	ADDWF usb_send_d_0005F_1_count, W, 1
	MOVWF FSR0L
	MOVF CompTempVar2699, W, 1
	MOVWF INDF0
	INCF usb_send_d_0005F_1_count, F, 1
	BRA	label22
label23
	MOVF usb_send_d_0005F_1_bdcount+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdcount, W, 1
	MOVWF FSR0L
	MOVF usb_send_d_0005F_1_count, W, 1
	MOVWF INDF0
	MOVF usb_send_d_0005F_1_bdaddr+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdaddr, W, 1
	MOVWF FSR0L
	INCF FSR0L, F
	MOVF usb_send_d_0005F_1_buffer, W, 1
	MOVWF CompTempVar2700, 1
	MOVF usb_send_d_0005F_1_buffer+D'1', W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2700, W, 1
	MOVWF INDF0
	BTFSS usb_send_d_0005F_arg_first,0, 1
	BRA	label24
	MOVF usb_send_d_0005F_1_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdstat, W, 1
	MOVWF FSR0L
	BCF INDF0,6
label24
	MOVF usb_send_d_0005F_1_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdstat, W, 1
	MOVWF FSR0L
	BTFSS INDF0,6
	BRA	label25
	MOVF usb_send_d_0005F_1_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdstat, W, 1
	MOVWF FSR0L
	BCF INDF0,6
	BRA	label26
label25
	MOVF usb_send_d_0005F_1_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdstat, W, 1
	MOVWF FSR0L
	BSF INDF0,6
label26
	MOVF usb_send_d_0005F_1_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_send_d_0005F_1_bdstat, W, 1
	MOVWF FSR0L
	BCF INDF0,5
	BCF INDF0,4
	BSF INDF0,3
	BCF INDF0,2
	BCF INDF0,1
	BCF INDF0,0
	BSF INDF0,7
	RETURN
; } usb_send_data function end

	ORG 0x000002EA
usb_get_de_00067
; { usb_get_descriptor_callback ; function begin
	CLRF usb_get_de_00067_1_descrip_0006C, 1
	CLRF usb_get_de_00067_1_descrip_0006C+D'1', 1
	DECF usb_get_de_00067_arg_descr_00068, W, 1
	BZ	label29
	MOVLW 0x02
	CPFSEQ usb_get_de_00067_arg_descr_00068, 1
	BRA	label27
	BRA	label30
label27
	MOVLW 0x03
	CPFSEQ usb_get_de_00067_arg_descr_00068, 1
	BRA	label28
	BRA	label31
label28
	MOVLW 0x06
	CPFSEQ usb_get_de_00067_arg_descr_00068, 1
	BRA	label35
	BRA	label35
label29
	MOVLW HIGH(gbl_my_device_descriptor+D'0')
	MOVWF CompTempVar2712, 1
	MOVLW LOW(gbl_my_device_descriptor+D'0')
	MOVWF usb_get_de_00067_1_descrip_0006C, 1
	MOVF CompTempVar2712, W, 1
	MOVWF usb_get_de_00067_1_descrip_0006C+D'1', 1
	MOVLW 0x12
	MOVWF usb_get_de_00067_1_descrip_0006D, 1
	CLRF usb_get_de_00067_1_descrip_0006D+D'1', 1
	BRA	label35
label30
	MOVLW HIGH(gbl_complete_serial_config_00000+D'0')
	MOVWF CompTempVar2713, 1
	MOVLW LOW(gbl_complete_serial_config_00000+D'0')
	MOVWF usb_get_de_00067_1_descrip_0006C, 1
	MOVF CompTempVar2713, W, 1
	MOVWF usb_get_de_00067_1_descrip_0006C+D'1', 1
	MOVLW 0x43
	MOVWF usb_get_de_00067_1_descrip_0006D, 1
	CLRF usb_get_de_00067_1_descrip_0006D+D'1', 1
	BRA	label35
label31
	MOVF usb_get_de_00067_arg_descr_00069, F, 1
	BZ	label32
	DECF usb_get_de_00067_arg_descr_00069, W, 1
	BZ	label33
	MOVLW 0x02
	CPFSEQ usb_get_de_00067_arg_descr_00069, 1
	BRA	label35
	BRA	label34
label32
	MOVLW 0x04
	MOVWF usb_get_de_00067_1_descrip_0006D, 1
	CLRF usb_get_de_00067_1_descrip_0006D+D'1', 1
	MOVLW HIGH(gbl_string_00+D'0')
	MOVWF CompTempVar2714, 1
	MOVLW LOW(gbl_string_00+D'0')
	MOVWF usb_get_de_00067_1_descrip_0006C, 1
	MOVF CompTempVar2714, W, 1
	MOVWF usb_get_de_00067_1_descrip_0006C+D'1', 1
	BRA	label35
label33
	MOVLW 0x2E
	MOVWF usb_get_de_00067_1_descrip_0006D, 1
	CLRF usb_get_de_00067_1_descrip_0006D+D'1', 1
	MOVLW HIGH(gbl_MX_USBMFR+D'0')
	MOVWF CompTempVar2715, 1
	MOVLW LOW(gbl_MX_USBMFR+D'0')
	MOVWF usb_get_de_00067_1_descrip_0006C, 1
	MOVF CompTempVar2715, W, 1
	MOVWF usb_get_de_00067_1_descrip_0006C+D'1', 1
	BRA	label35
label34
	MOVLW 0x28
	MOVWF usb_get_de_00067_1_descrip_0006D, 1
	CLRF usb_get_de_00067_1_descrip_0006D+D'1', 1
	MOVLW HIGH(gbl_MX_USBNAME+D'0')
	MOVWF CompTempVar2716, 1
	MOVLW LOW(gbl_MX_USBNAME+D'0')
	MOVWF usb_get_de_00067_1_descrip_0006C, 1
	MOVF CompTempVar2716, W, 1
	MOVWF usb_get_de_00067_1_descrip_0006C+D'1', 1
label35
	MOVF usb_get_de_00067_arg_rtn_d_0006A+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_get_de_00067_arg_rtn_d_0006A, W, 1
	MOVWF FSR0L
	INCF FSR0L, F
	MOVF usb_get_de_00067_1_descrip_0006C, W, 1
	MOVWF CompTempVar2717, 1
	MOVF usb_get_de_00067_1_descrip_0006C+D'1', W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2717, W, 1
	MOVWF INDF0
	MOVF usb_get_de_00067_arg_rtn_d_0006B+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_get_de_00067_arg_rtn_d_0006B, W, 1
	MOVWF FSR0L
	INCF FSR0L, F
	MOVF usb_get_de_00067_1_descrip_0006D, W, 1
	MOVWF CompTempVar2718, 1
	MOVF usb_get_de_00067_1_descrip_0006D+D'1', W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2718, W, 1
	MOVWF INDF0
	RETURN
; } usb_get_descriptor_callback function end

	ORG 0x000003AE
usb_device_00071
; { usb_device_configured_callback ; function begin
	MOVLW 0x01
	MOVLB 0x01
	MOVWF gbl_CDC_USB_status, 1
	RETURN
; } usb_device_configured_callback function end

	ORG 0x000003B6
usb_config_00072
; { usb_configure_endpoints ; function begin
	MOVLB 0x0F
	BSF gbl_uep2,4, 1
	BCF gbl_uep2,2, 1
	BSF gbl_uep2,1, 1
	BSF gbl_uep2,3, 1
	MOVLB 0x02
	BSF gbl_bd2in,6, 1
	BCF gbl_bd2in,5, 1
	BCF gbl_bd2in,4, 1
	BCF gbl_bd2in,3, 1
	BCF gbl_bd2in,2, 1
	BCF gbl_bd2in,1, 1
	BCF gbl_bd2in,0, 1
	BCF gbl_bd2in,7, 1
	MOVLB 0x0F
	BSF gbl_uep3,4, 1
	BSF gbl_uep3,2, 1
	BSF gbl_uep3,1, 1
	BSF gbl_uep3,3, 1
	MOVLB 0x02
	BSF gbl_bd3in,6, 1
	BCF gbl_bd3in,5, 1
	BCF gbl_bd3in,4, 1
	BCF gbl_bd3in,3, 1
	BCF gbl_bd3in,2, 1
	BCF gbl_bd3in,1, 1
	BCF gbl_bd3in,0, 1
	BCF gbl_bd3in,7, 1
	MOVLW 0x08
	MOVWF gbl_bd3out+D'1', 1
	MOVLW 0x98
	MOVWF gbl_bd3out+D'2', 1
	MOVLW 0x02
	MOVWF gbl_bd3out+D'3', 1
	BCF gbl_bd3out,6, 1
	BCF gbl_bd3out,5, 1
	BCF gbl_bd3out,4, 1
	BCF gbl_bd3out,3, 1
	BCF gbl_bd3out,2, 1
	BCF gbl_bd3out,1, 1
	BCF gbl_bd3out,0, 1
	BSF gbl_bd3out,7, 1
	RETURN
; } usb_configure_endpoints function end

	ORG 0x0000040C
usb_cdc_ha_00070
; { usb_cdc_handle_tx ; function begin
	MOVLW HIGH(gbl_bd3in+D'0')
	MOVLB 0x02
	MOVWF usb_cdc_ha_00070_1_bd+D'1', 1
	MOVLW LOW(gbl_bd3in+D'0')
	MOVWF usb_cdc_ha_00070_1_bd, 1
	MOVF usb_cdc_ha_00070_1_bd+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_cdc_ha_00070_1_bd, W, 1
	MOVWF FSR0L
	BTFSC INDF0,7
	RETURN
	MOVLB 0x01
	MOVF gbl_ep_in_buffer_size+D'6', W, 1
	MOVLB 0x02
	MOVWF usb_cdc_ha_00070_1_buffer_size, 1
	MOVLB 0x01
	MOVF gbl_ep_in_buffer_size+D'7', W, 1
	MOVLB 0x02
	MOVWF usb_cdc_ha_00070_1_buffer_size+D'1', 1
	MOVLB 0x01
	MOVF gbl_ep_in_buffer_location+D'6', W, 1
	MOVLB 0x02
	MOVWF usb_cdc_ha_00070_1_buffer, 1
	MOVLB 0x01
	MOVF gbl_ep_in_buffer_location+D'7', W, 1
	MOVLB 0x02
	MOVWF usb_cdc_ha_00070_1_buffer+D'1', 1
	MOVLB 0x01
	MOVF gbl_cdc_tx_start, W, 1
	CPFSEQ gbl_cdc_tx_end, 1
	BRA	label36
	RETURN
label36
	MOVLB 0x02
	BCF usb_cdc_ha_00070_1_store_gie,0, 1
	BTFSC gbl_intcon,7
	BSF usb_cdc_ha_00070_1_store_gie,0, 1
label37
	BCF gbl_intcon,7
	BTFSC gbl_intcon,7
	BRA	label37
	CLRF usb_cdc_ha_00070_1_count, 1
label38
	MOVLB 0x01
	MOVF gbl_cdc_tx_start, W, 1
	CPFSEQ gbl_cdc_tx_end, 1
	CPFSEQ gbl_cdc_tx_start, 1
	BRA	label40
	MOVLB 0x02
	MOVF usb_cdc_ha_00070_1_buffer_size, W, 1
	CPFSLT usb_cdc_ha_00070_1_count, 1
	MOVF usb_cdc_ha_00070_1_buffer_size+D'1', W, 1
	BZ	label40
	MOVLB 0x01
	INCF gbl_cdc_tx_start, W, 1
	MOVLB 0x02
	MOVWF usb_cdc_ha_00070_1_cdc_tx_next, 1
	MOVLW 0x40
	CPFSEQ usb_cdc_ha_00070_1_cdc_tx_next, 1
	BRA	label39
	CLRF usb_cdc_ha_00070_1_cdc_tx_next, 1
label39
	MOVLB 0x00
	LFSR 0x00, gbl_cdc_tx_buffer
	MOVF FSR0L, W
	MOVLB 0x01
	MOVF gbl_cdc_tx_start, W, 1
	MOVLB 0x02
	MOVWF CompTempVar2728, 1
	MOVF CompTempVar2728, W, 1
	ADDWF FSR0L, F
	MOVF INDF0, W
	MOVWF CompTempVar2729, 1
	MOVF usb_cdc_ha_00070_1_buffer+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_cdc_ha_00070_1_buffer, W, 1
	ADDWF usb_cdc_ha_00070_1_count, W, 1
	MOVWF FSR0L
	MOVF CompTempVar2729, W, 1
	MOVWF INDF0
	INCF usb_cdc_ha_00070_1_count, F, 1
	MOVF usb_cdc_ha_00070_1_cdc_tx_next, W, 1
	MOVLB 0x01
	MOVWF gbl_cdc_tx_start, 1
	BRA	label38
label40
	MOVLW 0x00
	MOVLB 0x02
	CPFSGT usb_cdc_ha_00070_1_count, 1
	BRA	label43
	MOVF usb_cdc_ha_00070_1_bd+D'1', W, 1
	MOVWF FSR0H
	INCF usb_cdc_ha_00070_1_bd, W, 1
	MOVWF FSR0L
	MOVF usb_cdc_ha_00070_1_count, W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVLW 0x02
	ADDWF FSR0L, F
	INCF FSR0L, F
	MOVF usb_cdc_ha_00070_1_buffer, W, 1
	MOVWF CompTempVar2730, 1
	MOVF usb_cdc_ha_00070_1_buffer+D'1', W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2730, W, 1
	MOVWF INDF0
	MOVF usb_cdc_ha_00070_1_bd, W, 1
	MOVWF FSR0L
	BTFSS INDF0,6
	BRA	label41
	MOVF usb_cdc_ha_00070_1_bd+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_cdc_ha_00070_1_bd, W, 1
	MOVWF FSR0L
	BCF INDF0,6
	BRA	label42
label41
	MOVF usb_cdc_ha_00070_1_bd+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_cdc_ha_00070_1_bd, W, 1
	MOVWF FSR0L
	BSF INDF0,6
label42
	MOVF usb_cdc_ha_00070_1_bd+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_cdc_ha_00070_1_bd, W, 1
	MOVWF FSR0L
	BCF INDF0,5
	BCF INDF0,4
	BSF INDF0,3
	BCF INDF0,2
	BCF INDF0,1
	BCF INDF0,0
	BSF INDF0,7
label43
	BTFSC usb_cdc_ha_00070_1_store_gie,0, 1
	BSF gbl_intcon,7
	BTFSS usb_cdc_ha_00070_1_store_gie,0, 1
	BCF gbl_intcon,7
	RETURN
; } usb_cdc_handle_tx function end

	ORG 0x00000518
memcpy8_00000
; { memcpy8 ; function begin
	MOVF memcpy8_00000_arg_dst, W, 1
	MOVWF memcpy8_00000_1_dst2, 1
	MOVF memcpy8_00000_arg_dst+D'1', W, 1
	MOVWF memcpy8_00000_1_dst2+D'1', 1
	MOVF memcpy8_00000_arg_src, W, 1
	MOVWF memcpy8_00000_1_src2, 1
	MOVF memcpy8_00000_arg_src+D'1', W, 1
	MOVWF memcpy8_00000_1_src2+D'1', 1
label44
	MOVLW 0x00
	CPFSGT memcpy8_00000_arg_len, 1
	BRA	label45
	MOVF memcpy8_00000_1_src2+D'1', W, 1
	MOVWF FSR0H
	MOVF memcpy8_00000_1_src2, W, 1
	MOVWF FSR0L
	INFSNZ memcpy8_00000_1_src2, F, 1
	INCF memcpy8_00000_1_src2+D'1', F, 1
	MOVF INDF0, W
	MOVWF CompTempVar411, 1
	MOVF memcpy8_00000_1_dst2+D'1', W, 1
	MOVWF FSR0H
	MOVF memcpy8_00000_1_dst2, W, 1
	MOVWF FSR0L
	INFSNZ memcpy8_00000_1_dst2, F, 1
	INCF memcpy8_00000_1_dst2+D'1', F, 1
	MOVF CompTempVar411, W, 1
	MOVWF INDF0
	DECF memcpy8_00000_arg_len, F, 1
	BRA	label44
label45
	MOVF memcpy8_00000_arg_dst, W, 1
	MOVWF CompTempVarRet410, 1
	MOVF memcpy8_00000_arg_dst+D'1', W, 1
	MOVWF CompTempVarRet410+D'1', 1
	RETURN
; } memcpy8 function end

	ORG 0x0000055C
usb_prime__00074
; { usb_prime_ep0_out ; function begin
	MOVLW 0x08
	MOVLB 0x02
	MOVWF gbl_bd0out+D'1', 1
	MOVLW 0x80
	MOVWF gbl_bd0out+D'2', 1
	MOVLW 0x02
	MOVWF gbl_bd0out+D'3', 1
	BSF gbl_bd0out,6, 1
	BCF gbl_bd0out,5, 1
	BCF gbl_bd0out,4, 1
	BSF gbl_bd0out,3, 1
	BCF gbl_bd0out,2, 1
	BCF gbl_bd0out,1, 1
	BCF gbl_bd0out,0, 1
	BSF gbl_bd0out,7, 1
	RETURN
; } usb_prime_ep0_out function end

	ORG 0x0000057C
usb_handle_00075
; { usb_handle_standard_request ; function begin
	MOVLW 0x06
	CPFSEQ usb_handle_00075_arg_sdp+D'1', 1
	BRA	label46
	BRA	label50
label46
	MOVLW 0x05
	CPFSEQ usb_handle_00075_arg_sdp+D'1', 1
	BRA	label47
	BRA	label53
label47
	MOVLW 0x09
	CPFSEQ usb_handle_00075_arg_sdp+D'1', 1
	BRA	label48
	BRA	label55
label48
	MOVLW 0x0A
	CPFSEQ usb_handle_00075_arg_sdp+D'1', 1
	BRA	label49
	BRA	label57
label49
	MOVF usb_handle_00075_arg_sdp+D'1', F, 1
	BZ	label59
	BRA	label61
label50
	MOVF usb_handle_00075_arg_sdp+D'3', W, 1
	MOVWF usb_handle_00075_1_descrip_00076, 1
	MOVF usb_handle_00075_arg_sdp+D'2', W, 1
	MOVWF usb_handle_00075_1_descrip_00077, 1
	MOVF usb_handle_00075_1_descrip_00076, W, 1
	MOVWF usb_get_de_00067_arg_descr_00068, 1
	MOVF usb_handle_00075_1_descrip_00077, W, 1
	MOVWF usb_get_de_00067_arg_descr_00069, 1
	MOVLW HIGH(gbl_delivery_ptr+D'0')
	MOVWF usb_get_de_00067_arg_rtn_d_0006A+D'1', 1
	MOVLW LOW(gbl_delivery_ptr+D'0')
	MOVWF usb_get_de_00067_arg_rtn_d_0006A, 1
	MOVLW HIGH(gbl_delivery_bytes_to_send+D'0')
	MOVWF usb_get_de_00067_arg_rtn_d_0006B+D'1', 1
	MOVLW LOW(gbl_delivery_bytes_to_send+D'0')
	MOVWF usb_get_de_00067_arg_rtn_d_0006B, 1
	CALL usb_get_de_00067
	MOVLB 0x01
	MOVF gbl_delivery_ptr, F, 1
	BNZ	label51
	MOVF gbl_delivery_ptr+D'1', F, 1
	BZ	label52
label51
	MOVLW 0x03
	MOVWF gbl_control_mode, 1
	MOVLB 0x02
	MOVF usb_handle_00075_arg_sdp+D'6', W, 1
	MOVLB 0x01
	MOVWF gbl_delivery_bytes_max_send, 1
	MOVLB 0x02
	MOVF usb_handle_00075_arg_sdp+D'7', W, 1
	MOVLB 0x01
	MOVWF gbl_delivery_bytes_max_send+D'1', 1
	CLRF gbl_delivery_bytes_sent, 1
	CLRF gbl_delivery_bytes_sent+D'1', 1
	MOVLW 0x08
	MOVWF gbl_delivery_buffer_size, 1
	MOVLW 0x88
	MOVWF gbl_delivery_buffer, 1
	MOVLW 0x02
	MOVWF gbl_delivery_buffer+D'1', 1
	MOVLB 0x02
	BCF gbl_bd0in,6, 1
	CALL usb_send_d_00061
	BRA	label62
label52
	CALL usb_stall__00062
	BRA	label62
label53
	MOVF usb_handle_00075_arg_sdp+D'2', W, 1
	MOVLB 0x01
	MOVWF gbl_usb_address, 1
	MOVLW 0x01
	MOVWF gbl_usb_status, 1
	MOVLW 0x08
	GOTO	usb_send_e_00060
label54
	MOVLW 0x06
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	BRA	label62
label55
	MOVLW 0x06
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	MOVLW 0x0C
	GOTO	usb_send_e_00060
label56
	MOVLW 0x03
	MOVLB 0x01
	MOVWF gbl_usb_state, 1
	CALL usb_config_00072
	CALL usb_device_00071
	BRA	label62
label57
	MOVLW 0x03
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	MOVLW 0x01
	MOVLB 0x02
	MOVWF usb_send_o_00073_arg_data, 1
	MOVLW 0x00
	GOTO	usb_send_o_00073
label58
	BRA	label62
label59
	CLRF usb_send_o_00073_arg_data, 1
	MOVLW 0x04
	GOTO	usb_send_o_00073
label60
	BRA	label62
label61
	CALL usb_stall__00062
label62
	GOTO	label78
; } usb_handle_standard_request function end

	ORG 0x0000065E
usb_handle_00066
; { usb_handle_class_request ; function begin
	MOVLW 0x20
	CPFSEQ usb_handle_00066_arg_sdp+D'1', 1
	BRA	label63
	BRA	label65
label63
	MOVLW 0x21
	CPFSEQ usb_handle_00066_arg_sdp+D'1', 1
	BRA	label64
	BRA	label66
label64
	MOVLW 0x22
	CPFSEQ usb_handle_00066_arg_sdp+D'1', 1
	BRA	label68
	BRA	label67
label65
	MOVLW 0x02
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	BRA	label68
label66
	MOVLW 0x04
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	MOVLB 0x02
	CLRF usb_send_d_0005F_arg_ep, 1
	MOVLW HIGH(gbl_class_data+D'0')
	MOVWF usb_send_d_0005F_arg_data+D'1', 1
	MOVLW LOW(gbl_class_data+D'0')
	MOVWF usb_send_d_0005F_arg_data, 1
	MOVLW 0x08
	MOVWF usb_send_d_0005F_arg_send_count, 1
	BSF usb_send_d_0005F_arg_first,0, 1
	CALL usb_send_d_0005F
	BRA	label68
label67
	MOVLW 0x06
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	MOVLW 0x04
	GOTO	usb_send_e_00060
label68
	GOTO	label80
; } usb_handle_class_request function end

	ORG 0x000006AC
usb_handle_00065
; { usb_handle_ctrl_write_class ; function begin
	MOVLW 0x20
	MOVLB 0x01
	CPFSEQ gbl_usb_sdp+D'1', 1
	BRA	label70
	MOVLW HIGH(gbl_class_data+D'0')
	MOVLB 0x02
	MOVWF memcpy8_00000_arg_dst+D'1', 1
	MOVLW LOW(gbl_class_data+D'0')
	MOVWF memcpy8_00000_arg_dst, 1
	MOVF usb_handle_00065_arg_data, W, 1
	MOVWF memcpy8_00000_arg_src, 1
	MOVF usb_handle_00065_arg_data+D'1', W, 1
	MOVWF memcpy8_00000_arg_src+D'1', 1
	MOVF usb_handle_00065_arg_count, W, 1
	MOVWF memcpy8_00000_arg_len, 1
	CALL memcpy8_00000
	MOVLW 0x06
	MOVLB 0x01
	MOVWF gbl_control_mode, 1
	MOVLW 0x00
	GOTO	usb_send_e_00060
label69
	MOVLW HIGH(gbl_class_data+D'0')
	MOVWF usb_handle_00065_1_my_lc+D'1', 1
	MOVLW LOW(gbl_class_data+D'0')
	MOVWF usb_handle_00065_1_my_lc, 1
label70
	GOTO	label90
; } usb_handle_ctrl_write_class function end

	ORG 0x000006E6
usb_handle_00064
; { usb_handle_ctrl_read_class ; function begin
	MOVLW 0x21
	MOVLB 0x01
	CPFSEQ gbl_usb_sdp+D'1', 1
	RETURN
	MOVLW 0x05
	MOVWF gbl_control_mode, 1
	RETURN
; } usb_handle_ctrl_read_class function end

	ORG 0x000006F4
usb_ep_dat_0006F
; { usb_ep_data_in_callback ; function begin
	CALL usb_cdc_ha_00070
	GOTO	label101
; } usb_ep_data_in_callback function end

	ORG 0x000006FC
usb_ep_dat_0006E
; { usb_ep_data_out_callback ; function begin
	MOVLW 0x03
	CPFSEQ usb_ep_dat_0006E_arg_end_point, 1
	RETURN
	CLRF usb_ep_dat_0006E_2_count, 1
label71
	MOVF usb_ep_dat_0006E_arg_byte_count, W, 1
	CPFSLT usb_ep_dat_0006E_2_count, 1
	MOVF usb_ep_dat_0006E_arg_byte_count+D'1', W, 1
	BTFSC STATUS,Z
	RETURN
	MOVLB 0x01
	INCF gbl_cdc_rx_end, W, 1
	MOVLB 0x02
	MOVWF usb_ep_dat_0006E_1_cdc_rx_next, 1
	MOVLW 0x40
	CPFSEQ usb_ep_dat_0006E_1_cdc_rx_next, 1
	BRA	label72
	CLRF usb_ep_dat_0006E_1_cdc_rx_next, 1
label72
	MOVLB 0x01
	MOVF gbl_cdc_rx_start, W, 1
	MOVLB 0x02
	CPFSEQ usb_ep_dat_0006E_1_cdc_rx_next, 1
	BRA	label73
	BRA	label74
label73
	MOVLB 0x01
	CPFSEQ gbl_cdc_rx_start, 1
label74
	BRA	label75
	MOVLB 0x02
	MOVF usb_ep_dat_0006E_arg_buffer+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_ep_dat_0006E_arg_buffer, W, 1
	MOVWF FSR0L
	MOVF usb_ep_dat_0006E_2_count, W, 1
	MOVWF CompTempVar2721, 1
	MOVF CompTempVar2721, W, 1
	ADDWF FSR0L, F
	MOVF INDF0, W
	MOVWF CompTempVar2722, 1
	MOVLB 0x00
	LFSR 0x00, gbl_cdc_rx_buffer
	MOVF FSR0L, W
	MOVLB 0x01
	MOVF gbl_cdc_rx_end, W, 1
	ADDWF FSR0L, F
	MOVLB 0x02
	MOVF CompTempVar2722, W, 1
	MOVWF INDF0
	MOVF usb_ep_dat_0006E_1_cdc_rx_next, W, 1
	MOVLB 0x01
	MOVWF gbl_cdc_rx_end, 1
label75
	MOVLB 0x02
	INCF usb_ep_dat_0006E_2_count, F, 1
	BRA	label71
; } usb_ep_data_out_callback function end

	ORG 0x00000766
usb_handle_0005C
; { usb_handle_stall ; function begin
	RETURN
; } usb_handle_stall function end

	ORG 0x00000768
usb_handle_0005B
; { usb_handle_reset ; function begin
	MOVLB 0x01
	CLRF gbl_usb_address, 1
	CLRF gbl_control_mode, 1
	CLRF gbl_usb_status, 1
	BCF gbl_uir,3
	BCF gbl_uir,3
	BCF gbl_uir,3
	BCF gbl_uir,3
	MOVLW 0x08
	MOVLB 0x02
	MOVWF gbl_bd0out+D'1', 1
	MOVLW 0x80
	MOVWF gbl_bd0out+D'2', 1
	MOVLW 0x02
	MOVWF gbl_bd0out+D'3', 1
	BCF gbl_bd0out,6, 1
	BCF gbl_bd0out,5, 1
	BCF gbl_bd0out,4, 1
	BCF gbl_bd0out,3, 1
	BCF gbl_bd0out,2, 1
	BCF gbl_bd0out,1, 1
	BCF gbl_bd0out,0, 1
	BSF gbl_bd0out,7, 1
	MOVLW 0x08
	MOVWF gbl_bd0in+D'1', 1
	MOVLW 0x88
	MOVWF gbl_bd0in+D'2', 1
	MOVLW 0x02
	MOVWF gbl_bd0in+D'3', 1
	BCF gbl_bd0in,6, 1
	BCF gbl_bd0in,5, 1
	BCF gbl_bd0in,4, 1
	BCF gbl_bd0in,2, 1
	BCF gbl_bd0in,1, 1
	BCF gbl_bd0in,0, 1
	BCF gbl_bd0in,7, 1
	RETURN
; } usb_handle_reset function end

	ORG 0x000007B2
usb_handle_0005A
; { usb_handle_transaction ; function begin
	RRCF gbl_ustat, W
	MOVLB 0x02
	MOVWF usb_handle_0005A_1_end_point, 1
	RRCF usb_handle_0005A_1_end_point, F, 1
	RRCF usb_handle_0005A_1_end_point, F, 1
	MOVLW 0x1F
	ANDWF usb_handle_0005A_1_end_point, F, 1
	BTFSS gbl_ustat,2
	BRA	label76
	RRCF gbl_bd0in, W, 1
	MOVWF usb_handle_0005A_1_pid, 1
	RRCF usb_handle_0005A_1_pid, F, 1
	MOVLW 0x3F
	ANDWF usb_handle_0005A_1_pid, F, 1
	MOVLW 0x0F
	ANDWF usb_handle_0005A_1_pid, F, 1
	BRA	label77
label76
	RRCF gbl_bd0out, W, 1
	MOVWF CompTempVar2651, 1
	RRCF CompTempVar2651, F, 1
	MOVLW 0x3F
	ANDWF CompTempVar2651, F, 1
	MOVLW 0x0F
	ANDWF CompTempVar2651, W, 1
	MOVWF usb_handle_0005A_1_pid, 1
label77
	MOVF usb_handle_0005A_1_end_point, F, 1
	BTFSS STATUS,Z
	BRA	label93
	MOVLW 0x0D
	CPFSEQ usb_handle_0005A_1_pid, 1
	BRA	label81
	MOVLW HIGH(gbl_usb_sdp+D'0')
	MOVWF memcpy8_00000_arg_dst+D'1', 1
	MOVLW LOW(gbl_usb_sdp+D'0')
	MOVWF memcpy8_00000_arg_dst, 1
	MOVLW HIGH(gbl_buffer_0_out+D'0')
	MOVWF memcpy8_00000_arg_src+D'1', 1
	MOVLW LOW(gbl_buffer_0_out+D'0')
	MOVWF memcpy8_00000_arg_src, 1
	MOVLW 0x08
	MOVWF memcpy8_00000_arg_len, 1
	CALL memcpy8_00000
	CALL usb_prime__00074
	MOVLW 0x40
	MOVLB 0x01
	ANDWF gbl_usb_sdp, W, 1
	MOVLB 0x02
	MOVWF CompTempVar2654, 1
	TSTFSZ CompTempVar2654, 1
	BRA	label79
	MOVLW 0x20
	MOVLB 0x01
	ANDWF gbl_usb_sdp, W, 1
	MOVLB 0x02
	MOVWF CompTempVar2655, 1
	TSTFSZ CompTempVar2655, 1
	BRA	label79
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'7', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'7', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'6', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'6', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'5', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'5', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'4', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'4', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'3', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'3', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'2', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'2', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'1', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp+D'1', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp, W, 1
	MOVLB 0x02
	MOVWF usb_handle_00075_arg_sdp, 1
	MOVLW 0x99
	GOTO	usb_handle_00075
label78
	BRA	label80
label79
	MOVLW 0x40
	MOVLB 0x01
	ANDWF gbl_usb_sdp, W, 1
	MOVLB 0x02
	MOVWF CompTempVar2657, 1
	TSTFSZ CompTempVar2657, 1
	BRA	label80
	MOVLB 0x01
	BTFSS gbl_usb_sdp,5, 1
	BRA	label80
	MOVF gbl_usb_sdp+D'7', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'7', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'6', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'6', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'5', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'5', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'4', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'4', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'3', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'3', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'2', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'2', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp+D'1', W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp+D'1', 1
	MOVLB 0x01
	MOVF gbl_usb_sdp, W, 1
	MOVLB 0x02
	MOVWF usb_handle_00066_arg_sdp, 1
	MOVLW 0x99
	GOTO	usb_handle_00066
label80
	BCF gbl_ucon,4
	BRA	label109
label81
	MOVLW 0x09
	CPFSEQ usb_handle_0005A_1_pid, 1
	BRA	label85
	MOVLW 0x03
	MOVLB 0x01
	CPFSEQ gbl_control_mode, 1
	BRA	label82
	CALL usb_send_d_00061
	BRA	label109
label82
	MOVLW 0x06
	CPFSEQ gbl_control_mode, 1
	BRA	label83
	CLRF gbl_control_mode, 1
	DECF gbl_usb_status, W, 1
	BTFSS STATUS,Z
	BRA	label109
	MOVLW 0x02
	MOVWF gbl_usb_state, 1
	MOVF gbl_usb_address, W, 1
	MOVLB 0x0F
	MOVWF gbl_uaddr, 1
	MOVLB 0x01
	CLRF gbl_usb_status, 1
	BRA	label109
label83
	MOVLW 0x05
	CPFSEQ gbl_control_mode, 1
	BRA	label84
	NOP
	BRA	label109
label84
	MOVLW 0x04
	CPFSEQ gbl_control_mode, 1
	BRA	label109
	CALL usb_handle_00064
	BRA	label109
label85
	MOVLW 0x02
	CPFSEQ usb_handle_0005A_1_pid, 1
	BRA	label88
	MOVLW 0x03
	MOVLB 0x01
	CPFSEQ gbl_control_mode, 1
	BRA	label86
	CALL usb_send_d_00061
	BRA	label109
label86
	MOVLW 0x04
	CPFSEQ gbl_control_mode, 1
	BRA	label87
	CALL usb_handle_00064
	BRA	label109
label87
	MOVLW 0x06
	CPFSEQ gbl_control_mode, 1
	BRA	label109
	CLRF gbl_control_mode, 1
	BRA	label109
label88
	DECF usb_handle_0005A_1_pid, W, 1
	BTFSS STATUS,Z
	BRA	label109
	MOVLW 0x05
	MOVLB 0x01
	CPFSEQ gbl_control_mode, 1
	BRA	label89
	CLRF gbl_control_mode, 1
	BRA	label92
label89
	MOVLW 0x02
	CPFSEQ gbl_control_mode, 1
	BRA	label91
	MOVLW HIGH(gbl_buffer_0_out+D'0')
	MOVLB 0x02
	MOVWF usb_handle_00065_arg_data+D'1', 1
	MOVLW LOW(gbl_buffer_0_out+D'0')
	MOVWF usb_handle_00065_arg_data, 1
	MOVF gbl_bd0out+D'1', W, 1
	MOVWF usb_handle_00065_arg_count, 1
	CLRF usb_handle_00065_arg_count+D'1', 1
	MOVLW 0x99
	GOTO	usb_handle_00065
label90
	BRA	label92
label91
	MOVLW 0x03
	CPFSEQ gbl_control_mode, 1
	BRA	label92
	CLRF gbl_control_mode, 1
label92
	CALL usb_prime__00074
	BRA	label109
label93
	BTFSS gbl_ustat,2
	BRA	label102
	MOVF usb_handle_0005A_1_end_point, F, 1
	BNZ	label94
	BRA	label96
label94
	DECF usb_handle_0005A_1_end_point, W, 1
	BZ	label97
	MOVLW 0x02
	CPFSEQ usb_handle_0005A_1_end_point, 1
	BRA	label95
	BRA	label98
label95
	MOVLW 0x03
	CPFSEQ usb_handle_0005A_1_end_point, 1
	BRA	label100
	BRA	label99
label96
	MOVF gbl_bd0in+D'1', W, 1
	MOVWF usb_handle_0005A_88_count, 1
	BRA	label100
label97
	MOVF gbl_bd1in+D'1', W, 1
	MOVWF usb_handle_0005A_88_count, 1
	BRA	label100
label98
	MOVF gbl_bd2in+D'1', W, 1
	MOVWF usb_handle_0005A_88_count, 1
	BRA	label100
label99
	MOVF gbl_bd3in+D'1', W, 1
	MOVWF usb_handle_0005A_88_count, 1
label100
	MOVF usb_handle_0005A_1_end_point, W, 1
	MOVWF usb_ep_dat_0006F_arg_end_point, 1
	MOVF usb_handle_0005A_88_count, W, 1
	MOVWF usb_ep_dat_0006F_arg_byte_count, 1
	CLRF usb_ep_dat_0006F_arg_byte_count+D'1', 1
	MOVLW 0x99
	GOTO	usb_ep_dat_0006F
label101
	BRA	label109
label102
	MOVF usb_handle_0005A_1_end_point, F, 1
	BZ	label104
	DECF usb_handle_0005A_1_end_point, W, 1
	BZ	label105
	MOVLW 0x02
	CPFSEQ usb_handle_0005A_1_end_point, 1
	BRA	label103
	BRA	label106
label103
	MOVLW 0x03
	CPFSEQ usb_handle_0005A_1_end_point, 1
	BRA	label108
	BRA	label107
label104
	MOVLW HIGH(gbl_bd0out+D'0')
	MOVWF usb_handle_0005A_97_bdstat+D'1', 1
	MOVLW LOW(gbl_bd0out+D'0')
	MOVWF usb_handle_0005A_97_bdstat, 1
	MOVLW HIGH(gbl_bd0out+D'1')
	MOVWF usb_handle_0005A_97_bdcount+D'1', 1
	MOVLW LOW(gbl_bd0out+D'1')
	MOVWF usb_handle_0005A_97_bdcount, 1
	BRA	label108
label105
	MOVLW HIGH(gbl_bd1out+D'0')
	MOVWF CompTempVar2663, 1
	MOVLW LOW(gbl_bd1out+D'0')
	MOVWF usb_handle_0005A_97_bdstat, 1
	MOVF CompTempVar2663, W, 1
	MOVWF usb_handle_0005A_97_bdstat+D'1', 1
	MOVLW HIGH(gbl_bd1out+D'1')
	MOVWF CompTempVar2664, 1
	MOVLW LOW(gbl_bd1out+D'1')
	MOVWF usb_handle_0005A_97_bdcount, 1
	MOVF CompTempVar2664, W, 1
	MOVWF usb_handle_0005A_97_bdcount+D'1', 1
	BRA	label108
label106
	MOVLW HIGH(gbl_bd2out+D'0')
	MOVWF CompTempVar2665, 1
	MOVLW LOW(gbl_bd2out+D'0')
	MOVWF usb_handle_0005A_97_bdstat, 1
	MOVF CompTempVar2665, W, 1
	MOVWF usb_handle_0005A_97_bdstat+D'1', 1
	MOVLW HIGH(gbl_bd2out+D'1')
	MOVWF CompTempVar2666, 1
	MOVLW LOW(gbl_bd2out+D'1')
	MOVWF usb_handle_0005A_97_bdcount, 1
	MOVF CompTempVar2666, W, 1
	MOVWF usb_handle_0005A_97_bdcount+D'1', 1
	BRA	label108
label107
	MOVLW HIGH(gbl_bd3out+D'0')
	MOVWF CompTempVar2667, 1
	MOVLW LOW(gbl_bd3out+D'0')
	MOVWF usb_handle_0005A_97_bdstat, 1
	MOVF CompTempVar2667, W, 1
	MOVWF usb_handle_0005A_97_bdstat+D'1', 1
	MOVLW HIGH(gbl_bd3out+D'1')
	MOVWF CompTempVar2668, 1
	MOVLW LOW(gbl_bd3out+D'1')
	MOVWF usb_handle_0005A_97_bdcount, 1
	MOVF CompTempVar2668, W, 1
	MOVWF usb_handle_0005A_97_bdcount+D'1', 1
label108
	MOVF usb_handle_0005A_1_end_point, W, 1
	MOVWF usb_ep_dat_0006E_arg_end_point, 1
	MOVLB 0x01
	LFSR 0x00, gbl_ep_out_buffer_location
	MOVF FSR0L, W
	MOVLB 0x02
	MOVF usb_handle_0005A_1_end_point, W, 1
	MOVWF CompTempVar2675, 1
	BCF STATUS,C
	RLCF CompTempVar2675, W, 1
	ADDWF FSR0L, F
	MOVF POSTINC0, W
	MOVWF usb_ep_dat_0006E_arg_buffer, 1
	MOVF INDF0, W
	MOVWF usb_ep_dat_0006E_arg_buffer+D'1', 1
	MOVF usb_handle_0005A_97_bdcount+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_handle_0005A_97_bdcount, W, 1
	MOVWF FSR0L
	MOVF INDF0, W
	MOVWF usb_ep_dat_0006E_arg_byte_count, 1
	CLRF usb_ep_dat_0006E_arg_byte_count+D'1', 1
	CALL usb_ep_dat_0006E
	MOVLB 0x01
	LFSR 0x00, gbl_ep_out_buffer_size
	MOVF FSR0L, W
	MOVLB 0x02
	MOVF usb_handle_0005A_1_end_point, W, 1
	MOVWF CompTempVar2678, 1
	BCF STATUS,C
	RLCF CompTempVar2678, F, 1
	MOVF CompTempVar2678, W, 1
	ADDWF FSR0L, F
	MOVF POSTINC0, W
	MOVWF CompTempVar2680, 1
	MOVF INDF0, W
	MOVWF CompTempVar2680+D'1', 1
	MOVF usb_handle_0005A_97_bdcount+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_handle_0005A_97_bdcount, W, 1
	MOVWF FSR0L
	MOVF CompTempVar2680, W, 1
	MOVWF INDF0
	MOVF usb_handle_0005A_97_bdstat+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_handle_0005A_97_bdstat, W, 1
	MOVWF FSR0L
	BCF INDF0,6
	BCF INDF0,5
	BCF INDF0,4
	BCF INDF0,3
	BCF INDF0,2
	BCF INDF0,1
	BCF INDF0,0
	BSF INDF0,7
label109
	GOTO	label111
; } usb_handle_transaction function end

	ORG 0x00000AB0
usb_SOF_ca_0005D
; { usb_SOF_callback ; function begin
	CALL usb_cdc_ha_00070
	GOTO	label115
; } usb_SOF_callback function end

	ORG 0x00000AB8
usb_handle_00059
; { usb_handle_isr ; function begin
	BTFSS gbl_pir2,2
	BRA	label116
	BCF gbl_pir2,2
	BTFSS gbl_uir,4
	BRA	label110
	BCF gbl_uir,4
label110
	BTFSS gbl_uir,3
	BRA	label112
	MOVLW 0x99
	GOTO	usb_handle_0005A
label111
	BCF gbl_uir,3
label112
	BTFSS gbl_uir,0
	BRA	label113
	CALL usb_handle_0005B
	BCF gbl_uir,0
label113
	BTFSS gbl_uir,5
	BRA	label114
	CALL usb_handle_0005C
	BCF gbl_uir,5
label114
	BTFSS gbl_uir,6
	BRA	label116
	MOVLB 0x0F
	MOVF gbl_ufrml, W, 1
	MOVLB 0x02
	MOVWF usb_SOF_ca_0005D_arg_frame, 1
	CLRF usb_SOF_ca_0005D_arg_frame+D'1', 1
	MOVLW 0x99
	GOTO	usb_SOF_ca_0005D
label115
	BCF gbl_uir,6
label116
	GOTO	label153
; } usb_handle_isr function end

	ORG 0x00000AFE
usb_setup_00000
; { usb_setup ; function begin
	MOVLB 0x01
	CLRF gbl_usb_state, 1
	BCF gbl_ucfg,3
	BSF gbl_ucfg,2
	BSF gbl_ucfg,4
	BCF gbl_ucfg,1
	BCF gbl_ucfg,0
	MOVLB 0x0F
	BSF gbl_uep0,4, 1
	BSF gbl_uep0,2, 1
	BSF gbl_uep0,1, 1
	BCF gbl_uep0,3, 1
	BSF gbl_uie,5
	BSF gbl_uie,3
	BSF gbl_uie,0
	BSF gbl_pie2,2
	BSF gbl_uie,6
	RETURN
; } usb_setup function end

	ORG 0x00000B22
usb_ep_get_0007D
; { usb_ep_get_rx_buffer ; function begin
	MOVLW 0x40
	CPFSGT usb_ep_get_0007D_arg_length, 1
	BRA	label117
	MOVLW 0x40
	MOVWF usb_ep_get_0007D_arg_length, 1
label117
	CLRF usb_ep_get_0007D_1_count, 1
label118
	MOVF usb_ep_get_0007D_arg_length, W, 1
	CPFSLT usb_ep_get_0007D_1_count, 1
	BRA	label119
	MOVLB 0x00
	LFSR 0x00, gbl_cdc_rx_buffer
	MOVF FSR0L, W
	MOVLB 0x01
	MOVF usb_ep_get_0007D_1_count, W, 1
	MOVWF CompTempVar2749, 1
	MOVF CompTempVar2749, W, 1
	ADDWF FSR0L, F
	MOVF INDF0, W
	MOVWF CompTempVar2750, 1
	MOVF usb_ep_get_0007D_arg_buffer+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_ep_get_0007D_arg_buffer, W, 1
	ADDWF usb_ep_get_0007D_1_count, W, 1
	MOVWF FSR0L
	MOVF CompTempVar2750, W, 1
	MOVWF INDF0
	INCF usb_ep_get_0007D_1_count, F, 1
	BRA	label118
label119
	MOVF gbl_cdc_rx_start, W, 1
	MOVWF gbl_cdc_rx_end, 1
	RETURN
; } usb_ep_get_rx_buffer function end

	ORG 0x00000B62
usb_enable_0005E
; { usb_enable_module ; function begin
	CLRF gbl_uir
	BSF gbl_ucon,3
	MOVLW 0x01
	MOVLB 0x01
	MOVWF gbl_usb_state, 1
	RETURN
; } usb_enable_module function end

	ORG 0x00000B6E
usb_config_0007E
; { usb_configure_structures ; function begin
	MOVLW 0x12
	MOVWF gbl_my_device_descriptor
	MOVLW 0x01
	MOVWF gbl_my_device_descriptor+D'1'
	MOVLW 0x10
	MOVWF gbl_my_device_descriptor+D'2'
	MOVLW 0x01
	MOVWF gbl_my_device_descriptor+D'3'
	MOVLW 0x02
	MOVWF gbl_my_device_descriptor+D'4'
	CLRF gbl_my_device_descriptor+D'5'
	CLRF gbl_my_device_descriptor+D'6'
	MOVLW 0x08
	MOVWF gbl_my_device_descriptor+D'7'
	MOVLW 0xBF
	MOVWF gbl_my_device_descriptor+D'8'
	MOVLW 0x12
	MOVWF gbl_my_device_descriptor+D'9'
	MOVLW 0x10
	MOVWF gbl_my_device_descriptor+D'10'
	MOVLW 0xF0
	MOVWF gbl_my_device_descriptor+D'11'
	CLRF gbl_my_device_descriptor+D'12'
	MOVLW 0x01
	MOVWF gbl_my_device_descriptor+D'13'
	MOVWF gbl_my_device_descriptor+D'14'
	MOVLW 0x02
	MOVWF gbl_my_device_descriptor+D'15'
	CLRF gbl_my_device_descriptor+D'16'
	MOVLW 0x01
	MOVWF gbl_my_device_descriptor+D'17'
	MOVLW 0x09
	MOVLB 0x00
	MOVWF gbl_my_config, 1
	MOVLW 0x02
	MOVWF gbl_my_config+D'1', 1
	MOVLW 0x43
	MOVWF gbl_my_config+D'2', 1
	CLRF gbl_my_config+D'3', 1
	MOVLW 0x02
	MOVWF gbl_my_config+D'4', 1
	MOVLW 0x01
	MOVWF gbl_my_config+D'5', 1
	CLRF gbl_my_config+D'6', 1
	MOVLW 0x80
	MOVWF gbl_my_config+D'7', 1
	MOVLW 0x64
	MOVWF gbl_my_config+D'8', 1
	MOVLW 0x09
	MOVWF gbl_my_comm_interface, 1
	MOVLW 0x04
	MOVWF gbl_my_comm_interface+D'1', 1
	CLRF gbl_my_comm_interface+D'2', 1
	CLRF gbl_my_comm_interface+D'3', 1
	MOVLW 0x01
	MOVWF gbl_my_comm_interface+D'4', 1
	MOVLW 0x02
	MOVWF gbl_my_comm_interface+D'5', 1
	MOVWF gbl_my_comm_interface+D'6', 1
	MOVLW 0x01
	MOVWF gbl_my_comm_interface+D'7', 1
	CLRF gbl_my_comm_interface+D'8', 1
	MOVLW 0x05
	MOVWF gbl_my_header
	MOVLW 0x24
	MOVWF gbl_my_header+D'1'
	CLRF gbl_my_header+D'2'
	MOVLW 0x10
	MOVWF gbl_my_header+D'3'
	MOVLW 0x01
	MOVWF gbl_my_header+D'4'
	MOVLW 0x04
	MOVLB 0x01
	MOVWF gbl_my_ACM, 1
	MOVLW 0x24
	MOVWF gbl_my_ACM+D'1', 1
	MOVLW 0x02
	MOVWF gbl_my_ACM+D'2', 1
	MOVWF gbl_my_ACM+D'3', 1
	MOVLW 0x05
	MOVWF gbl_my_union, 1
	MOVLW 0x24
	MOVWF gbl_my_union+D'1', 1
	MOVLW 0x06
	MOVWF gbl_my_union+D'2', 1
	CLRF gbl_my_union+D'3', 1
	MOVLW 0x01
	MOVWF gbl_my_union+D'4', 1
	MOVLW 0x05
	MOVWF gbl_my_call_mgt, 1
	MOVLW 0x24
	MOVWF gbl_my_call_mgt+D'1', 1
	MOVLW 0x01
	MOVWF gbl_my_call_mgt+D'2', 1
	CLRF gbl_my_call_mgt+D'3', 1
	MOVLW 0x01
	MOVWF gbl_my_call_mgt+D'4', 1
	MOVLW 0x07
	MOVWF gbl_my_notification_ep, 1
	MOVLW 0x05
	MOVWF gbl_my_notification_ep+D'1', 1
	MOVLW 0x82
	MOVWF gbl_my_notification_ep+D'2', 1
	MOVLW 0x03
	MOVWF gbl_my_notification_ep+D'3', 1
	MOVLW 0x08
	MOVWF gbl_my_notification_ep+D'4', 1
	CLRF gbl_my_notification_ep+D'5', 1
	MOVLW 0x02
	MOVWF gbl_my_notification_ep+D'6', 1
	MOVLW 0x09
	MOVWF gbl_my_data_interface, 1
	MOVLW 0x04
	MOVWF gbl_my_data_interface+D'1', 1
	MOVLW 0x01
	MOVWF gbl_my_data_interface+D'2', 1
	CLRF gbl_my_data_interface+D'3', 1
	MOVLW 0x02
	MOVWF gbl_my_data_interface+D'4', 1
	MOVLW 0x0A
	MOVWF gbl_my_data_interface+D'5', 1
	CLRF gbl_my_data_interface+D'6', 1
	CLRF gbl_my_data_interface+D'7', 1
	CLRF gbl_my_data_interface+D'8', 1
	MOVLW 0x07
	MOVWF gbl_my_data_out_ep, 1
	MOVLW 0x05
	MOVWF gbl_my_data_out_ep+D'1', 1
	MOVLW 0x03
	MOVWF gbl_my_data_out_ep+D'2', 1
	MOVLW 0x02
	MOVWF gbl_my_data_out_ep+D'3', 1
	MOVLW 0x08
	MOVWF gbl_my_data_out_ep+D'4', 1
	CLRF gbl_my_data_out_ep+D'5', 1
	CLRF gbl_my_data_out_ep+D'6', 1
	MOVLW 0x07
	MOVWF gbl_my_data_in_ep, 1
	MOVLW 0x05
	MOVWF gbl_my_data_in_ep+D'1', 1
	MOVLW 0x83
	MOVWF gbl_my_data_in_ep+D'2', 1
	MOVLW 0x02
	MOVWF gbl_my_data_in_ep+D'3', 1
	MOVLW 0x08
	MOVWF gbl_my_data_in_ep+D'4', 1
	CLRF gbl_my_data_in_ep+D'5', 1
	CLRF gbl_my_data_in_ep+D'6', 1
	MOVLB 0x00
	MOVF gbl_my_config+D'8', W, 1
	MOVWF gbl_complete_serial_config_00000+D'8'
	MOVF gbl_my_config+D'7', W, 1
	MOVWF gbl_complete_serial_config_00000+D'7'
	MOVF gbl_my_config+D'6', W, 1
	MOVWF gbl_complete_serial_config_00000+D'6'
	MOVF gbl_my_config+D'5', W, 1
	MOVWF gbl_complete_serial_config_00000+D'5'
	MOVF gbl_my_config+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'4'
	MOVF gbl_my_config+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'3'
	MOVF gbl_my_config+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'2'
	MOVF gbl_my_config+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'1'
	MOVF gbl_my_config, W, 1
	MOVWF gbl_complete_serial_config_00000
	MOVF gbl_my_comm_interface+D'8', W, 1
	MOVWF gbl_complete_serial_config_00000+D'17'
	MOVF gbl_my_comm_interface+D'7', W, 1
	MOVWF gbl_complete_serial_config_00000+D'16'
	MOVF gbl_my_comm_interface+D'6', W, 1
	MOVWF gbl_complete_serial_config_00000+D'15'
	MOVF gbl_my_comm_interface+D'5', W, 1
	MOVWF gbl_complete_serial_config_00000+D'14'
	MOVF gbl_my_comm_interface+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'13'
	MOVF gbl_my_comm_interface+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'12'
	MOVF gbl_my_comm_interface+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'11'
	MOVF gbl_my_comm_interface+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'10'
	MOVF gbl_my_comm_interface, W, 1
	MOVWF gbl_complete_serial_config_00000+D'9'
	MOVF gbl_my_header+D'4', W
	MOVWF gbl_complete_serial_config_00000+D'22'
	MOVF gbl_my_header+D'3', W
	MOVWF gbl_complete_serial_config_00000+D'21'
	MOVF gbl_my_header+D'2', W
	MOVWF gbl_complete_serial_config_00000+D'20'
	MOVF gbl_my_header+D'1', W
	MOVWF gbl_complete_serial_config_00000+D'19'
	MOVF gbl_my_header, W
	MOVWF gbl_complete_serial_config_00000+D'18'
	MOVLB 0x01
	MOVF gbl_my_ACM+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'26'
	MOVF gbl_my_ACM+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'25'
	MOVF gbl_my_ACM+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'24'
	MOVF gbl_my_ACM, W, 1
	MOVWF gbl_complete_serial_config_00000+D'23'
	MOVF gbl_my_union+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'31'
	MOVF gbl_my_union+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'30'
	MOVF gbl_my_union+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'29'
	MOVF gbl_my_union+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'28'
	MOVF gbl_my_union, W, 1
	MOVWF gbl_complete_serial_config_00000+D'27'
	MOVF gbl_my_call_mgt+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'36'
	MOVF gbl_my_call_mgt+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'35'
	MOVF gbl_my_call_mgt+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'34'
	MOVF gbl_my_call_mgt+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'33'
	MOVF gbl_my_call_mgt, W, 1
	MOVWF gbl_complete_serial_config_00000+D'32'
	MOVF gbl_my_notification_ep+D'6', W, 1
	MOVWF gbl_complete_serial_config_00000+D'43'
	MOVF gbl_my_notification_ep+D'5', W, 1
	MOVWF gbl_complete_serial_config_00000+D'42'
	MOVF gbl_my_notification_ep+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'41'
	MOVF gbl_my_notification_ep+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'40'
	MOVF gbl_my_notification_ep+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'39'
	MOVF gbl_my_notification_ep+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'38'
	MOVF gbl_my_notification_ep, W, 1
	MOVWF gbl_complete_serial_config_00000+D'37'
	MOVF gbl_my_data_interface+D'8', W, 1
	MOVWF gbl_complete_serial_config_00000+D'52'
	MOVF gbl_my_data_interface+D'7', W, 1
	MOVWF gbl_complete_serial_config_00000+D'51'
	MOVF gbl_my_data_interface+D'6', W, 1
	MOVWF gbl_complete_serial_config_00000+D'50'
	MOVF gbl_my_data_interface+D'5', W, 1
	MOVWF gbl_complete_serial_config_00000+D'49'
	MOVF gbl_my_data_interface+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'48'
	MOVF gbl_my_data_interface+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'47'
	MOVF gbl_my_data_interface+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'46'
	MOVF gbl_my_data_interface+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'45'
	MOVF gbl_my_data_interface, W, 1
	MOVWF gbl_complete_serial_config_00000+D'44'
	MOVF gbl_my_data_out_ep+D'6', W, 1
	MOVWF gbl_complete_serial_config_00000+D'59'
	MOVF gbl_my_data_out_ep+D'5', W, 1
	MOVWF gbl_complete_serial_config_00000+D'58'
	MOVF gbl_my_data_out_ep+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'57'
	MOVF gbl_my_data_out_ep+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'56'
	MOVF gbl_my_data_out_ep+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'55'
	MOVF gbl_my_data_out_ep+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'54'
	MOVF gbl_my_data_out_ep, W, 1
	MOVWF gbl_complete_serial_config_00000+D'53'
	MOVF gbl_my_data_in_ep+D'6', W, 1
	MOVWF gbl_complete_serial_config_00000+D'66'
	MOVF gbl_my_data_in_ep+D'5', W, 1
	MOVWF gbl_complete_serial_config_00000+D'65'
	MOVF gbl_my_data_in_ep+D'4', W, 1
	MOVWF gbl_complete_serial_config_00000+D'64'
	MOVF gbl_my_data_in_ep+D'3', W, 1
	MOVWF gbl_complete_serial_config_00000+D'63'
	MOVF gbl_my_data_in_ep+D'2', W, 1
	MOVWF gbl_complete_serial_config_00000+D'62'
	MOVF gbl_my_data_in_ep+D'1', W, 1
	MOVWF gbl_complete_serial_config_00000+D'61'
	MOVF gbl_my_data_in_ep, W, 1
	MOVWF gbl_complete_serial_config_00000+D'60'
	RETURN
; } usb_configure_structures function end

	ORG 0x00000DA8
usb_cdc_se_0007C
; { usb_cdc_setup ; function begin
	MOVLW HIGH(gbl_class_data+D'0')
	MOVLB 0x01
	MOVWF usb_cdc_se_0007C_1_my_lc+D'1', 1
	MOVLW LOW(gbl_class_data+D'0')
	MOVWF usb_cdc_se_0007C_1_my_lc, 1
	MOVF usb_cdc_se_0007C_1_my_lc+D'1', W, 1
	MOVWF FSR0H
	MOVF usb_cdc_se_0007C_1_my_lc, W, 1
	MOVWF FSR0L
	MOVLW 0x03
	ADDWF FSR0L, F
	MOVLW 0x00
	MOVWF CompTempVar2746, 1
	MOVWF CompTempVar2746+D'1', 1
	MOVLW 0x09
	MOVWF CompTempVar2746+D'2', 1
	MOVLW 0x60
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2746+D'2', W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2746+D'1', W, 1
	MOVWF INDF0
	DECF FSR0L, F
	MOVF CompTempVar2746, W, 1
	MOVWF INDF0
	MOVF usb_cdc_se_0007C_1_my_lc, W, 1
	MOVWF FSR0L
	MOVLW 0x04
	ADDWF FSR0L, F
	MOVLW 0x00
	MOVWF INDF0
	MOVF usb_cdc_se_0007C_1_my_lc, W, 1
	MOVWF FSR0L
	MOVLW 0x06
	ADDWF FSR0L, F
	MOVLW 0x08
	MOVWF INDF0
	MOVF usb_cdc_se_0007C_1_my_lc, W, 1
	MOVWF FSR0L
	MOVLW 0x05
	ADDWF FSR0L, F
	MOVLW 0x00
	MOVWF INDF0
	RETURN
; } usb_cdc_setup function end

	ORG 0x00000E04
usb_cdc_rx_00079
; { usb_cdc_rx_avail ; function begin
	MOVLB 0x01
	MOVF gbl_cdc_rx_start, W, 1
	SUBWF gbl_cdc_rx_end, W, 1
	MOVWF CompTempVarRet2736, 1
	RETURN
; } usb_cdc_rx_avail function end

	ORG 0x00000E0E
__mul_32_3_00007
; { __mul_32_32 ; function begin
	CLRF CompTempVarRet426, 1
	CLRF CompTempVarRet426+D'1', 1
	CLRF CompTempVarRet426+D'2', 1
	CLRF CompTempVarRet426+D'3', 1
	CLRF CompTempVarRet426+D'2', 1
	CLRF CompTempVarRet426+D'3', 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a, W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b, 1
	MOVF gbl_prodl, W
	MOVWF CompTempVarRet426, 1
	MOVF gbl_prodh, W
	MOVWF CompTempVarRet426+D'1', 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a+D'1', W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b, 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'1', F, 1
	MOVF gbl_prodh, W
	ADDWFC CompTempVarRet426+D'2', F, 1
	BTFSC gbl_status,0
	INCF CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a+D'2', W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b, 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'2', F, 1
	MOVF gbl_prodh, W
	ADDWFC CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a+D'3', W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b, 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a, W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b+D'1', 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'1', F, 1
	MOVF gbl_prodh, W
	ADDWFC CompTempVarRet426+D'2', F, 1
	BTFSC gbl_status,0
	INCF CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a+D'1', W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b+D'1', 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'2', F, 1
	MOVF gbl_prodh, W
	ADDWFC CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a+D'2', W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b+D'1', 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a, W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b+D'2', 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'2', F, 1
	MOVF gbl_prodh, W
	ADDWFC CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a+D'1', W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b+D'2', 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'3', F, 1
	MOVLB 0x01
	MOVF __mul_32_3_00007_arg_a, W, 1
	MOVLB 0x02
	MULWF __mul_32_3_00007_arg_b+D'3', 1
	MOVF gbl_prodl, W
	ADDWF CompTempVarRet426+D'3', F, 1
	RETURN
; } __mul_32_32 function end

	ORG 0x00000EB4
Wdt_Delay__00036
; { Wdt_Delay_Ms ; function begin
	CLRF Wdt_Delay__00036_1_i, 1
label120
	MOVF Wdt_Delay__00036_arg_delay, W, 1
	CPFSLT Wdt_Delay__00036_1_i, 1
	RETURN
	CLRWDT
	MOVLW 0x01
	MOVWF delay_ms_00000_arg_del, 1
	CALL delay_ms_00000
	INCF Wdt_Delay__00036_1_i, F, 1
	BRA	label120
; } Wdt_Delay_Ms function end

	ORG 0x00000ECA
FC_CAL_PWM_00052
; { FC_CAL_PWM_SetDuty10Bit_1 ; function begin
	MOVLW 0xFC
	ANDWF FC_CAL_PWM_00052_arg_duty, W, 1
	MOVWF CompTempVar2643, 1
	MOVF FC_CAL_PWM_00052_arg_duty+D'1', W, 1
	ANDLW 0x03
	MOVWF CompTempVar2642, 1
	RRCF CompTempVar2642, F, 1
	RRCF CompTempVar2643, F, 1
	RRCF CompTempVar2642, F, 1
	RRCF CompTempVar2643, F, 1
	MOVF CompTempVar2643, W, 1
	MOVWF gbl_ccpr1l
	MOVLW 0x03
	ANDWF FC_CAL_PWM_00052_arg_duty, F, 1
	CLRF CompTempVar2647, 1
	RLCF FC_CAL_PWM_00052_arg_duty, F, 1
	RLCF CompTempVar2647, F, 1
	RLCF FC_CAL_PWM_00052_arg_duty, F, 1
	RLCF CompTempVar2647, F, 1
	RLCF FC_CAL_PWM_00052_arg_duty, F, 1
	RLCF CompTempVar2647, F, 1
	RLCF FC_CAL_PWM_00052_arg_duty, F, 1
	RLCF CompTempVar2647, F, 1
	MOVLW 0xF0
	ANDWF FC_CAL_PWM_00052_arg_duty, F, 1
	MOVF CompTempVar2647, W, 1
	MOVWF FC_CAL_PWM_00052_arg_duty+D'1', 1
	MOVLW 0xCF
	ANDWF gbl_ccp1con, W
	MOVWF FC_CAL_PWM_00052_1_nCCPxCONtemp, 1
	MOVF FC_CAL_PWM_00052_arg_duty, W, 1
	IORWF FC_CAL_PWM_00052_1_nCCPxCONtemp, F, 1
	MOVF FC_CAL_PWM_00052_1_nCCPxCONtemp, W, 1
	MOVWF gbl_ccp1con
	RETURN
; } FC_CAL_PWM_SetDuty10Bit_1 function end

	ORG 0x00000F10
FC_CAL_PWM_00051
; { FC_CAL_PWM_Enable_1 ; function begin
	BCF gbl_trisc,5
	BCF gbl_portc,5
	MOVLW 0xC0
	MOVWF gbl_pwm1con
	RETURN
; } FC_CAL_PWM_Enable_1 function end

	ORG 0x00000F1A
FC_CAL_PWM_0004E
; { FC_CAL_PWM_ChangePeriod_1 ; function begin
	MOVF FC_CAL_PWM_0004E_arg_period, W, 1
	MOVWF gbl_pr2
	MOVLW 0x01
	CPFSEQ FC_CAL_PWM_0004E_arg_prescaler, 1
	BRA	label121
	MOVF FC_CAL_PWM_0004E_arg_prescaler+D'1', W, 1
	BZ	label124
label121
	MOVLW 0x04
	CPFSEQ FC_CAL_PWM_0004E_arg_prescaler, 1
	BRA	label122
	MOVF FC_CAL_PWM_0004E_arg_prescaler+D'1', W, 1
	BZ	label125
label122
	MOVLW 0x10
	CPFSEQ FC_CAL_PWM_0004E_arg_prescaler, 1
	BRA	label123
	MOVF FC_CAL_PWM_0004E_arg_prescaler+D'1', W, 1
	BZ	label126
label123
	MOVLW 0x40
	CPFSEQ FC_CAL_PWM_0004E_arg_prescaler, 1
	BRA	label128
	MOVF FC_CAL_PWM_0004E_arg_prescaler+D'1', W, 1
	BZ	label127
	BRA	label128
label124
	MOVLW 0x04
	MOVWF gbl_t2con
	RETURN
label125
	MOVLW 0x05
	MOVWF gbl_t2con
	RETURN
label126
	MOVLW 0x06
	MOVWF gbl_t2con
	RETURN
label127
	MOVLW 0x07
	MOVWF gbl_t2con
	RETURN
label128
	MOVLW 0x05
	MOVWF gbl_t2con
	RETURN
; } FC_CAL_PWM_ChangePeriod_1 function end

	ORG 0x00000F66
FCI_STRING_0004B
; { FCI_STRING_TO_INT ; function begin
	CLRF FCI_STRING_0004B_1_bNegative, 1
	CLRF FCI_STRING_0004B_1_idx, 1
	CLRF FCI_STRING_0004B_1_RetVal, 1
	CLRF FCI_STRING_0004B_1_RetVal+D'1', 1
	CLRF FCI_STRING_0004B_1_RetVal+D'2', 1
	CLRF FCI_STRING_0004B_1_RetVal+D'3', 1
label129
	MOVF FCI_STRING_0004B_arg_MSZ_String, W, 1
	CPFSLT FCI_STRING_0004B_1_idx, 1
	BRA	label133
	MOVF FCI_STRING_0004B_arg_String+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_STRING_0004B_arg_String, W, 1
	ADDWF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FSR0L
	MOVLW 0x30
	CPFSLT INDF0
	BRA	label130
	BRA	label131
label130
	MOVF FCI_STRING_0004B_arg_String+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_STRING_0004B_arg_String, W, 1
	ADDWF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FSR0L
	MOVLW 0x39
	CPFSGT INDF0
	BRA	label133
label131
	MOVF FCI_STRING_0004B_arg_String+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_STRING_0004B_arg_String, W, 1
	ADDWF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FSR0L
	MOVLW 0x2D
	CPFSEQ INDF0
	BRA	label132
	MOVLW 0x01
	MOVWF FCI_STRING_0004B_1_bNegative, 1
	INCF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FCI_STRING_0004B_1_idx, 1
	BRA	label133
label132
	INCF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FCI_STRING_0004B_1_idx, 1
	BRA	label129
label133
	MOVF FCI_STRING_0004B_arg_MSZ_String, W, 1
	CPFSLT FCI_STRING_0004B_1_idx, 1
	BRA	label135
	MOVF FCI_STRING_0004B_arg_String+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_STRING_0004B_arg_String, W, 1
	ADDWF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FSR0L
	MOVLW 0x30
	CPFSLT INDF0
	BRA	label134
	BRA	label135
label134
	MOVF FCI_STRING_0004B_arg_String+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_STRING_0004B_arg_String, W, 1
	ADDWF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FSR0L
	MOVF INDF0, W
	SUBLW 0x39
	BNC	label135
	MOVF FCI_STRING_0004B_1_RetVal, W, 1
	MOVWF __mul_32_3_00007_arg_a, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'1', W, 1
	MOVWF __mul_32_3_00007_arg_a+D'1', 1
	MOVF FCI_STRING_0004B_1_RetVal+D'2', W, 1
	MOVWF __mul_32_3_00007_arg_a+D'2', 1
	MOVF FCI_STRING_0004B_1_RetVal+D'3', W, 1
	MOVWF __mul_32_3_00007_arg_a+D'3', 1
	MOVLW 0x0A
	MOVLB 0x02
	MOVWF __mul_32_3_00007_arg_b, 1
	CLRF __mul_32_3_00007_arg_b+D'1', 1
	CLRF __mul_32_3_00007_arg_b+D'2', 1
	CLRF __mul_32_3_00007_arg_b+D'3', 1
	CALL __mul_32_3_00007
	MOVF CompTempVarRet426, W, 1
	MOVLB 0x01
	MOVWF CompTempVar1984, 1
	MOVLB 0x02
	MOVF CompTempVarRet426+D'1', W, 1
	MOVLB 0x01
	MOVWF CompTempVar1985, 1
	MOVLB 0x02
	MOVF CompTempVarRet426+D'2', W, 1
	MOVLB 0x01
	MOVWF CompTempVar1986, 1
	MOVLB 0x02
	MOVF CompTempVarRet426+D'3', W, 1
	MOVWF CompTempVar1987, 1
	MOVLB 0x01
	MOVF CompTempVar1984, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal, 1
	MOVF CompTempVar1985, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'1', 1
	MOVF CompTempVar1986, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'2', 1
	MOVLB 0x02
	MOVF CompTempVar1987, W, 1
	MOVLB 0x01
	MOVWF FCI_STRING_0004B_1_RetVal+D'3', 1
	MOVF FCI_STRING_0004B_arg_String+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_STRING_0004B_arg_String, W, 1
	ADDWF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FSR0L
	MOVLW 0x30
	SUBWF INDF0, W
	MOVWF CompTempVar1990, 1
	CLRF CompTempVar1991, 1
	CLRF CompTempVar1992, 1
	CLRF CompTempVar1993, 1
	MOVF FCI_STRING_0004B_1_RetVal, W, 1
	ADDWF CompTempVar1990, F, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'1', W, 1
	ADDWFC CompTempVar1991, F, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'2', W, 1
	ADDWFC CompTempVar1992, F, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'3', W, 1
	ADDWFC CompTempVar1993, F, 1
	MOVF CompTempVar1990, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal, 1
	MOVF CompTempVar1991, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'1', 1
	MOVF CompTempVar1992, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'2', 1
	MOVF CompTempVar1993, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'3', 1
	INCF FCI_STRING_0004B_1_idx, W, 1
	MOVWF FCI_STRING_0004B_1_idx, 1
	BRA	label133
label135
	MOVF FCI_STRING_0004B_1_bNegative, F, 1
	BZ	label136
	MOVF FCI_STRING_0004B_1_RetVal, W, 1
	SUBLW 0x00
	MOVWF CompTempVar1995, 1
	MOVLW 0x00
	MOVWF CompTempVar1996, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'1', W, 1
	SUBWFB CompTempVar1996, F, 1
	MOVLW 0x00
	MOVWF CompTempVar1997, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'2', W, 1
	SUBWFB CompTempVar1997, F, 1
	MOVLW 0x00
	MOVWF CompTempVar1998, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'3', W, 1
	SUBWFB CompTempVar1998, F, 1
	MOVF CompTempVar1995, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal, 1
	MOVF CompTempVar1996, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'1', 1
	MOVF CompTempVar1997, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'2', 1
	MOVF CompTempVar1998, W, 1
	MOVWF FCI_STRING_0004B_1_RetVal+D'3', 1
label136
	MOVF FCI_STRING_0004B_1_RetVal, W, 1
	MOVWF CompTempVarRet1971, 1
	MOVF FCI_STRING_0004B_1_RetVal+D'1', W, 1
	MOVWF CompTempVarRet1971+D'1', 1
	MOVF FCI_STRING_0004B_1_RetVal+D'2', W, 1
	MOVWF CompTempVarRet1971+D'2', 1
	MOVF FCI_STRING_0004B_1_RetVal+D'3', W, 1
	MOVWF CompTempVarRet1971+D'3', 1
	RETURN
; } FCI_STRING_TO_INT function end

	ORG 0x000010B4
FCI_RIGHTS_00040
; { FCI_RIGHTSTRING ; function begin
	MOVF FCI_RIGHTS_00040_arg_iDst_len, F, 1
	BNZ	label137
	MOVF FCI_RIGHTS_00040_arg_sDst, W, 1
	MOVWF CompTempVarRet1866, 1
	MOVF FCI_RIGHTS_00040_arg_sDst+D'1', W, 1
	MOVWF CompTempVarRet1866+D'1', 1
	RETURN
label137
	CLRF FCI_RIGHTS_00040_1_idx, 1
label138
	MOVF FCI_RIGHTS_00040_arg_iSrc_len, W, 1
	CPFSLT FCI_RIGHTS_00040_1_idx, 1
	BRA	label139
	MOVF FCI_RIGHTS_00040_arg_sSrc+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_RIGHTS_00040_arg_sSrc, W, 1
	ADDWF FCI_RIGHTS_00040_1_idx, W, 1
	MOVWF FSR0L
	MOVF INDF0, F
	BZ	label139
	INCF FCI_RIGHTS_00040_1_idx, F, 1
	BRA	label138
label139
	MOVF FCI_RIGHTS_00040_arg_iCount, W, 1
	CPFSLT FCI_RIGHTS_00040_1_idx, 1
	BRA	label140
	MOVF FCI_RIGHTS_00040_1_idx, W, 1
	MOVWF FCI_RIGHTS_00040_arg_iCount, 1
label140
	MOVF FCI_RIGHTS_00040_arg_iCount, W, 1
	SUBWF FCI_RIGHTS_00040_1_idx, W, 1
	MOVWF FCI_RIGHTS_00040_1_delta, 1
	MOVF FCI_RIGHTS_00040_arg_iCount, W, 1
	CPFSLT FCI_RIGHTS_00040_arg_iDst_len, 1
	BRA	label141
	MOVF FCI_RIGHTS_00040_arg_iDst_len, W, 1
	MOVWF FCI_RIGHTS_00040_arg_iCount, 1
label141
	MOVF FCI_RIGHTS_00040_1_delta, W, 1
	ADDWF FCI_RIGHTS_00040_arg_sSrc, F, 1
	BTFSC STATUS,C
	INCF FCI_RIGHTS_00040_arg_sSrc+D'1', F, 1
	CLRF FCI_RIGHTS_00040_1_idx, 1
label142
	MOVF FCI_RIGHTS_00040_arg_iCount, W, 1
	CPFSLT FCI_RIGHTS_00040_1_idx, 1
	BRA	label143
	MOVF FCI_RIGHTS_00040_arg_sSrc+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_RIGHTS_00040_arg_sSrc, W, 1
	MOVWF FSR0L
	MOVF INDF0, W
	MOVWF CompTempVar1868, 1
	MOVF FCI_RIGHTS_00040_arg_sDst+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_RIGHTS_00040_arg_sDst, W, 1
	MOVWF FSR0L
	MOVF CompTempVar1868, W, 1
	MOVWF INDF0
	INFSNZ FCI_RIGHTS_00040_arg_sDst, F, 1
	INCF FCI_RIGHTS_00040_arg_sDst+D'1', F, 1
	INFSNZ FCI_RIGHTS_00040_arg_sSrc, F, 1
	INCF FCI_RIGHTS_00040_arg_sSrc+D'1', F, 1
	INCF FCI_RIGHTS_00040_1_idx, F, 1
	BRA	label142
label143
	MOVF FCI_RIGHTS_00040_arg_iDst_len, W, 1
	CPFSLT FCI_RIGHTS_00040_1_idx, 1
	BRA	label144
	MOVF FCI_RIGHTS_00040_arg_sDst+D'1', W, 1
	MOVWF FSR0H
	MOVF FCI_RIGHTS_00040_arg_sDst, W, 1
	MOVWF FSR0L
	MOVLW 0x00
	MOVWF INDF0
label144
	MOVF FCI_RIGHTS_00040_arg_sDst, W, 1
	MOVWF CompTempVarRet1866, 1
	MOVF FCI_RIGHTS_00040_arg_sDst+D'1', W, 1
	MOVWF CompTempVarRet1866+D'1', 1
	RETURN
; } FCI_RIGHTSTRING function end

	ORG 0x00001146
FCD_0df41__00058
; { FCD_0df41_PWM1__SetDutyCycle10Bit ; function begin
	MOVF gbl_FCV_0df41_PWM1__ENABLED, F, 1
	BTFSC STATUS,Z
	RETURN
	MOVF FCD_0df41__00058_arg_FCL_DUTY, W, 1
	MOVWF FC_CAL_PWM_00052_arg_duty, 1
	MOVF FCD_0df41__00058_arg_FCL_DUTY+D'1', W, 1
	MOVWF FC_CAL_PWM_00052_arg_duty+D'1', 1
	CALL FC_CAL_PWM_00052
	RETURN
; } FCD_0df41_PWM1__SetDutyCycle10Bit function end

	ORG 0x0000115A
FCD_0df41__00057
; { FCD_0df41_PWM1__Enable ; function begin
	MOVLW 0x01
	MOVLB 0x01
	MOVWF gbl_FCV_0df41_PWM1__ENABLED, 1
	SETF FC_CAL_PWM_0004E_arg_period, 1
	CLRF FC_CAL_PWM_0004E_arg_period+D'1', 1
	MOVLW 0x01
	MOVWF FC_CAL_PWM_0004E_arg_prescaler, 1
	CLRF FC_CAL_PWM_0004E_arg_prescaler+D'1', 1
	CALL FC_CAL_PWM_0004E
	CALL FC_CAL_PWM_00051
	RETURN
; } FCD_0df41_PWM1__Enable function end

	ORG 0x00001174
FCD_056e1__00088
; { FCD_056e1_v5__usbserial0__Initialise ; function begin
	MOVLB 0x01
	CLRF FCD_056e1__00088_1_FCL_DEL_00089, 1
	CLRF FCD_056e1__00088_1_FCL_DEL_00089+D'1', 1
	CALL usb_config_0007E
label145
	BCF gbl_intcon,7
	BTFSC gbl_intcon,7
	BRA	label145
	CALL usb_cdc_se_0007C
	CALL usb_setup_00000
	BSF gbl_intcon,6
	BSF gbl_intcon,7
	CALL usb_enable_0005E
label146
	MOVF gbl_CDC_USB_status, F, 1
	BZ	label146
	CLRF FCD_056e1__00088_1_FCR_RETVAL, 1
	MOVF FCD_056e1__00088_1_FCR_RETVAL, W, 1
	MOVWF CompTempVarRet2765, 1
	RETURN
; } FCD_056e1_v5__usbserial0__Initialise function end

	ORG 0x000011A0
FCD_056e1__00080
; { FCD_056e1_v5__usbserial0__ReadString ; function begin
	CLRF FCD_056e1__00080_1_FCL_WAI_00083, 1
	INCF FCD_056e1__00080_arg_FCL_T_00082, W, 1
	BNZ	label147
	MOVLW 0x01
	MOVWF FCD_056e1__00080_1_FCL_WAI_00083, 1
label147
	MOVF FCD_056e1__00080_arg_FCL_T_00082, F, 1
	BNZ	label148
	MOVF FCD_056e1__00080_1_FCL_WAI_00083, F, 1
	BTFSC STATUS,Z
	RETURN
label148
	CALL usb_cdc_rx_00079
	MOVF CompTempVarRet2736, W, 1
	MOVWF FCD_056e1__00080_1_Rx_Length, 1
	MOVF FCD_056e1__00080_1_Rx_Length, F, 1
	BZ	label150
	MOVF FCD_056e1__00080_1_Rx_Length, W, 1
	CPFSLT FCD_056e1__00080_arg_FCL_LENGTH, 1
	BRA	label149
	MOVF FCD_056e1__00080_arg_FCL_LENGTH, W, 1
	MOVWF FCD_056e1__00080_1_Rx_Length, 1
label149
	MOVF FCD_056e1__00080_1_Rx_Length, W, 1
	MOVWF usb_ep_get_0007D_arg_length, 1
	MOVF FCD_056e1__00080_arg_FCR_RETVAL, W, 1
	MOVWF usb_ep_get_0007D_arg_buffer, 1
	MOVF FCD_056e1__00080_arg_FCR_RETVAL+D'1', W, 1
	MOVWF usb_ep_get_0007D_arg_buffer+D'1', 1
	CALL usb_ep_get_0007D
	MOVF FCD_056e1__00080_arg_FCL_LENGTH, W, 1
	CPFSLT FCD_056e1__00080_1_Rx_Length, 1
	RETURN
	MOVF FCD_056e1__00080_arg_FCR_RETVAL+D'1', W, 1
	MOVWF FSR0H
	MOVF FCD_056e1__00080_arg_FCR_RETVAL, W, 1
	ADDWF FCD_056e1__00080_1_Rx_Length, W, 1
	MOVWF FSR0L
	MOVLW 0x00
	MOVWF INDF0
	RETURN
label150
	MOVLW 0x01
	MOVWF Wdt_Delay__00036_arg_delay, 1
	CALL Wdt_Delay__00036
	DECF FCD_056e1__00080_arg_FCL_T_00082, W, 1
	MOVWF FCD_056e1__00080_arg_FCL_T_00082, 1
	BRA	label147
; } FCD_056e1_v5__usbserial0__ReadString function end

	ORG 0x000011FE
main
; { main ; function begin
	CLRF gbl_ansel
	CLRF gbl_anselh
	CALL FCD_0df41__00057
	CALL FCD_056e1__00088
label151
	MOVLW HIGH(gbl_FCV_INSTRING+D'0')
	MOVWF FCD_056e1__00080_arg_FCR_RETVAL+D'1', 1
	MOVLW LOW(gbl_FCV_INSTRING+D'0')
	MOVWF FCD_056e1__00080_arg_FCR_RETVAL, 1
	MOVLW 0x03
	MOVWF FCD_056e1__00080_arg_FCRsz_00081, 1
	CLRF FCD_056e1__00080_arg_FCRsz_00081+D'1', 1
	MOVLW 0x01
	MOVWF FCD_056e1__00080_arg_FCL_T_00082, 1
	MOVLW 0x03
	MOVWF FCD_056e1__00080_arg_FCL_LENGTH, 1
	CALL FCD_056e1__00080
	MOVLW 0x31
	CPFSEQ gbl_FCV_INSTRING, 1
	BRA	label151
	MOVLW HIGH(gbl_FCV_INSTRING+D'0')
	MOVWF FCI_RIGHTS_00040_arg_sSrc+D'1', 1
	MOVLW LOW(gbl_FCV_INSTRING+D'0')
	MOVWF FCI_RIGHTS_00040_arg_sSrc, 1
	MOVLW 0x03
	MOVWF FCI_RIGHTS_00040_arg_iSrc_len, 1
	MOVLW 0x02
	MOVWF FCI_RIGHTS_00040_arg_iCount, 1
	MOVLW HIGH(gbl_FCV_INSTRING+D'0')
	MOVWF FCI_RIGHTS_00040_arg_sDst+D'1', 1
	MOVLW LOW(gbl_FCV_INSTRING+D'0')
	MOVWF FCI_RIGHTS_00040_arg_sDst, 1
	MOVLW 0x03
	MOVWF FCI_RIGHTS_00040_arg_iDst_len, 1
	CALL FCI_RIGHTS_00040
	MOVLW HIGH(gbl_FCV_INSTRING+D'0')
	MOVWF FCI_STRING_0004B_arg_String+D'1', 1
	MOVLW LOW(gbl_FCV_INSTRING+D'0')
	MOVWF FCI_STRING_0004B_arg_String, 1
	MOVLW 0x03
	MOVWF FCI_STRING_0004B_arg_MSZ_String, 1
	CALL FCI_STRING_0004B
	MOVF CompTempVarRet1971, W, 1
	MOVWF gbl_FCV_READINPUT, 1
	MOVF CompTempVarRet1971+D'1', W, 1
	MOVWF gbl_FCV_READINPUT+D'1', 1
	MOVF gbl_FCV_READINPUT, W, 1
	MOVWF FCD_0df41__00058_arg_FCL_DUTY, 1
	MOVF gbl_FCV_READINPUT+D'1', W, 1
	MOVWF FCD_0df41__00058_arg_FCL_DUTY+D'1', 1
	CALL FCD_0df41__00058
	BRA	label151
; } main function end

	ORG 0x00001270
_startup
	MOVLW 0xD5
	MOVLB 0x00
	MOVWF gbl_14_LSR, 1
	MOVLW 0xC4
	MOVWF gbl_14_LSR+D'1', 1
	MOVLW 0xBB
	MOVWF gbl_14_LSR+D'2', 1
	MOVLW 0xDC
	MOVWF gbl_14_LSR+D'3', 1
	MOVLB 0x01
	CLRF gbl_15_gbl_aSig, 1
	CLRF gbl_15_gbl_aSig+D'1', 1
	CLRF gbl_15_gbl_aSig+D'2', 1
	CLRF gbl_15_gbl_aSig+D'3', 1
	CLRF gbl_15_gbl_bSig, 1
	CLRF gbl_15_gbl_bSig+D'1', 1
	CLRF gbl_15_gbl_bSig+D'2', 1
	CLRF gbl_15_gbl_bSig+D'3', 1
	CLRF gbl_15_gbl_zSig, 1
	CLRF gbl_15_gbl_zSig+D'1', 1
	CLRF gbl_15_gbl_zSig+D'2', 1
	CLRF gbl_15_gbl_zSig+D'3', 1
	CLRF gbl_15_gbl_aExp, 1
	CLRF gbl_15_gbl_bExp, 1
	CLRF gbl_15_gbl_zExp, 1
	CLRF gbl_15_gbl_zExp+D'1', 1
	CLRF gbl_15_gbl_aSign, 1
	CLRF gbl_15_gbl_bSign, 1
	CLRF gbl_15_gbl_zSign, 1
	CLRF gbl_15_gbl_zSigZero, 1
	CLRF gbl_15_gbl_ret, 1
	CLRF gbl_15_gbl_ret+D'1', 1
	CLRF gbl_15_gbl_ret+D'2', 1
	CLRF gbl_15_gbl_ret+D'3', 1
	CLRF gbl_float_rounding_mode, 1
	CLRF gbl_float_exception_flags, 1
	CLRF gbl_float_detect_tininess
	CLRF gbl_FCV_0df41_PWM1__ENABLED, 1
	MOVLW 0x28
	MOVWF gbl_MX_USBNAME, 1
	MOVLW 0x03
	MOVWF gbl_MX_USBNAME+D'1', 1
	MOVLW 0x46
	MOVWF gbl_MX_USBNAME+D'2', 1
	CLRF gbl_MX_USBNAME+D'3', 1
	MOVLW 0x6C
	MOVWF gbl_MX_USBNAME+D'4', 1
	CLRF gbl_MX_USBNAME+D'5', 1
	MOVLW 0x6F
	MOVWF gbl_MX_USBNAME+D'6', 1
	CLRF gbl_MX_USBNAME+D'7', 1
	MOVLW 0x77
	MOVWF gbl_MX_USBNAME+D'8', 1
	CLRF gbl_MX_USBNAME+D'9', 1
	MOVLW 0x63
	MOVWF gbl_MX_USBNAME+D'10', 1
	CLRF gbl_MX_USBNAME+D'11', 1
	MOVLW 0x6F
	MOVWF gbl_MX_USBNAME+D'12', 1
	CLRF gbl_MX_USBNAME+D'13', 1
	MOVLW 0x64
	MOVWF gbl_MX_USBNAME+D'14', 1
	CLRF gbl_MX_USBNAME+D'15', 1
	MOVLW 0x65
	MOVWF gbl_MX_USBNAME+D'16', 1
	CLRF gbl_MX_USBNAME+D'17', 1
	MOVLW 0x20
	MOVWF gbl_MX_USBNAME+D'18', 1
	CLRF gbl_MX_USBNAME+D'19', 1
	MOVLW 0x55
	MOVWF gbl_MX_USBNAME+D'20', 1
	CLRF gbl_MX_USBNAME+D'21', 1
	MOVLW 0x53
	MOVWF gbl_MX_USBNAME+D'22', 1
	CLRF gbl_MX_USBNAME+D'23', 1
	MOVLW 0x42
	MOVWF gbl_MX_USBNAME+D'24', 1
	CLRF gbl_MX_USBNAME+D'25', 1
	MOVLW 0x20
	MOVWF gbl_MX_USBNAME+D'26', 1
	CLRF gbl_MX_USBNAME+D'27', 1
	MOVLW 0x53
	MOVWF gbl_MX_USBNAME+D'28', 1
	CLRF gbl_MX_USBNAME+D'29', 1
	MOVLW 0x65
	MOVWF gbl_MX_USBNAME+D'30', 1
	CLRF gbl_MX_USBNAME+D'31', 1
	MOVLW 0x72
	MOVWF gbl_MX_USBNAME+D'32', 1
	CLRF gbl_MX_USBNAME+D'33', 1
	MOVLW 0x69
	MOVWF gbl_MX_USBNAME+D'34', 1
	CLRF gbl_MX_USBNAME+D'35', 1
	MOVLW 0x61
	MOVWF gbl_MX_USBNAME+D'36', 1
	CLRF gbl_MX_USBNAME+D'37', 1
	MOVLW 0x6C
	MOVWF gbl_MX_USBNAME+D'38', 1
	CLRF gbl_MX_USBNAME+D'39', 1
	MOVLW 0x2E
	MOVWF gbl_MX_USBMFR, 1
	MOVLW 0x03
	MOVWF gbl_MX_USBMFR+D'1', 1
	MOVLW 0x4D
	MOVWF gbl_MX_USBMFR+D'2', 1
	CLRF gbl_MX_USBMFR+D'3', 1
	MOVLW 0x61
	MOVWF gbl_MX_USBMFR+D'4', 1
	CLRF gbl_MX_USBMFR+D'5', 1
	MOVLW 0x74
	MOVWF gbl_MX_USBMFR+D'6', 1
	CLRF gbl_MX_USBMFR+D'7', 1
	MOVLW 0x72
	MOVWF gbl_MX_USBMFR+D'8', 1
	CLRF gbl_MX_USBMFR+D'9', 1
	MOVLW 0x69
	MOVWF gbl_MX_USBMFR+D'10', 1
	CLRF gbl_MX_USBMFR+D'11', 1
	MOVLW 0x78
	MOVWF gbl_MX_USBMFR+D'12', 1
	CLRF gbl_MX_USBMFR+D'13', 1
	MOVLW 0x20
	MOVWF gbl_MX_USBMFR+D'14', 1
	CLRF gbl_MX_USBMFR+D'15', 1
	MOVLW 0x4D
	MOVWF gbl_MX_USBMFR+D'16', 1
	CLRF gbl_MX_USBMFR+D'17', 1
	MOVLW 0x75
	MOVWF gbl_MX_USBMFR+D'18', 1
	CLRF gbl_MX_USBMFR+D'19', 1
	MOVLW 0x6C
	MOVWF gbl_MX_USBMFR+D'20', 1
	CLRF gbl_MX_USBMFR+D'21', 1
	MOVLW 0x74
	MOVWF gbl_MX_USBMFR+D'22', 1
	CLRF gbl_MX_USBMFR+D'23', 1
	MOVLW 0x69
	MOVWF gbl_MX_USBMFR+D'24', 1
	CLRF gbl_MX_USBMFR+D'25', 1
	MOVLW 0x6D
	MOVWF gbl_MX_USBMFR+D'26', 1
	CLRF gbl_MX_USBMFR+D'27', 1
	MOVLW 0x65
	MOVWF gbl_MX_USBMFR+D'28', 1
	CLRF gbl_MX_USBMFR+D'29', 1
	MOVLW 0x64
	MOVWF gbl_MX_USBMFR+D'30', 1
	CLRF gbl_MX_USBMFR+D'31', 1
	MOVLW 0x69
	MOVWF gbl_MX_USBMFR+D'32', 1
	CLRF gbl_MX_USBMFR+D'33', 1
	MOVLW 0x61
	MOVWF gbl_MX_USBMFR+D'34', 1
	CLRF gbl_MX_USBMFR+D'35', 1
	MOVLW 0x20
	MOVWF gbl_MX_USBMFR+D'36', 1
	CLRF gbl_MX_USBMFR+D'37', 1
	MOVLW 0x4C
	MOVWF gbl_MX_USBMFR+D'38', 1
	CLRF gbl_MX_USBMFR+D'39', 1
	MOVLW 0x74
	MOVWF gbl_MX_USBMFR+D'40', 1
	CLRF gbl_MX_USBMFR+D'41', 1
	MOVLW 0x64
	MOVWF gbl_MX_USBMFR+D'42', 1
	CLRF gbl_MX_USBMFR+D'43', 1
	MOVLW 0x2E
	MOVWF gbl_MX_USBMFR+D'44', 1
	CLRF gbl_MX_USBMFR+D'45', 1
	MOVLW 0x0A
	MOVLB 0x00
	MOVWF gbl_MX_SERIAL, 1
	MOVLW 0x03
	MOVWF gbl_MX_SERIAL+D'1', 1
	MOVLW 0x30
	MOVWF gbl_MX_SERIAL+D'2', 1
	CLRF gbl_MX_SERIAL+D'3', 1
	MOVLW 0x30
	MOVWF gbl_MX_SERIAL+D'4', 1
	CLRF gbl_MX_SERIAL+D'5', 1
	MOVLW 0x30
	MOVWF gbl_MX_SERIAL+D'6', 1
	CLRF gbl_MX_SERIAL+D'7', 1
	MOVLW 0x31
	MOVWF gbl_MX_SERIAL+D'8', 1
	CLRF gbl_MX_SERIAL+D'9', 1
	MOVLW HIGH(gbl_buffer_0_in+D'0')
	MOVLB 0x01
	MOVWF CompGblVar60, 1
	MOVLW LOW(gbl_buffer_0_in+D'0')
	MOVWF gbl_ep_in_buffer_location, 1
	MOVF CompGblVar60, W, 1
	MOVWF gbl_ep_in_buffer_location+D'1', 1
	CLRF gbl_ep_in_buffer_location+D'2', 1
	CLRF gbl_ep_in_buffer_location+D'3', 1
	MOVLW HIGH(gbl_buffer_2_in+D'0')
	MOVWF CompGblVar61, 1
	MOVLW LOW(gbl_buffer_2_in+D'0')
	MOVWF gbl_ep_in_buffer_location+D'4', 1
	MOVF CompGblVar61, W, 1
	MOVWF gbl_ep_in_buffer_location+D'5', 1
	MOVLW HIGH(gbl_buffer_3_in+D'0')
	MOVWF CompGblVar62, 1
	MOVLW LOW(gbl_buffer_3_in+D'0')
	MOVWF gbl_ep_in_buffer_location+D'6', 1
	MOVF CompGblVar62, W, 1
	MOVWF gbl_ep_in_buffer_location+D'7', 1
	MOVLW HIGH(gbl_buffer_0_out+D'0')
	MOVWF CompGblVar63, 1
	MOVLW LOW(gbl_buffer_0_out+D'0')
	MOVWF gbl_ep_out_buffer_location, 1
	MOVF CompGblVar63, W, 1
	MOVWF gbl_ep_out_buffer_location+D'1', 1
	CLRF gbl_ep_out_buffer_location+D'2', 1
	CLRF gbl_ep_out_buffer_location+D'3', 1
	CLRF gbl_ep_out_buffer_location+D'4', 1
	CLRF gbl_ep_out_buffer_location+D'5', 1
	MOVLW HIGH(gbl_buffer_3_out+D'0')
	MOVWF CompGblVar64, 1
	MOVLW LOW(gbl_buffer_3_out+D'0')
	MOVWF gbl_ep_out_buffer_location+D'6', 1
	MOVF CompGblVar64, W, 1
	MOVWF gbl_ep_out_buffer_location+D'7', 1
	MOVLW 0x08
	MOVWF gbl_ep_in_buffer_size, 1
	CLRF gbl_ep_in_buffer_size+D'1', 1
	CLRF gbl_ep_in_buffer_size+D'2', 1
	CLRF gbl_ep_in_buffer_size+D'3', 1
	MOVLW 0x08
	MOVWF gbl_ep_in_buffer_size+D'4', 1
	CLRF gbl_ep_in_buffer_size+D'5', 1
	MOVLW 0x08
	MOVWF gbl_ep_in_buffer_size+D'6', 1
	CLRF gbl_ep_in_buffer_size+D'7', 1
	MOVLW 0x08
	MOVWF gbl_ep_out_buffer_size, 1
	CLRF gbl_ep_out_buffer_size+D'1', 1
	CLRF gbl_ep_out_buffer_size+D'2', 1
	CLRF gbl_ep_out_buffer_size+D'3', 1
	CLRF gbl_ep_out_buffer_size+D'4', 1
	CLRF gbl_ep_out_buffer_size+D'5', 1
	MOVLW 0x08
	MOVWF gbl_ep_out_buffer_size+D'6', 1
	CLRF gbl_ep_out_buffer_size+D'7', 1
	CLRF gbl_usb_state, 1
	CLRF gbl_cdc_tx_start, 1
	CLRF gbl_cdc_tx_end, 1
	CLRF gbl_cdc_rx_start, 1
	CLRF gbl_cdc_rx_end, 1
	MOVLW 0x04
	MOVWF gbl_string_00, 1
	MOVLW 0x03
	MOVWF gbl_string_00+D'1', 1
	MOVLW 0x09
	MOVWF gbl_string_00+D'2', 1
	MOVLW 0x04
	MOVWF gbl_string_00+D'3', 1
	CLRF gbl_CDC_USB_status, 1
	GOTO	main
	ORG 0x00001478
interrupt
; { interrupt ; function begin
	MOVFF FSR0H,  Int1Context
	MOVFF FSR0L,  Int1Context+D'1'
	MOVFF PRODH,  Int1Context+D'2'
	MOVFF PRODL,  Int1Context+D'3'
	MOVLW 0x99
	GOTO	usb_handle_00059
label153
	MOVFF Int1Context+D'3',  PRODL
	MOVFF Int1Context+D'2',  PRODH
	MOVFF Int1Context+D'1',  FSR0L
	MOVFF Int1Context,  FSR0H
	RETFIE 1
; } interrupt function end

	ORG 0x00300000
	DW 0x3238
	DW 0x1E1F
	DW 0x8808
	DW 0xC003
	DW 0xE003
	DW 0xFFFF
	DW 0xFFFF
	END

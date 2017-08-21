    ;
    ;
    ; For more information look at http://www.microchip.com/forums/m957860.aspx
    ; or 4th page of http://ww1.microchip.com/downloads/en/DeviceDoc/80000712A.pdf
    ;
    ;
    
    #include <xc.inc>
    
    GLOBAL    powerup, start
    PSECT    powerup, class=CODE, delta=1, reloc=2
powerup:
    BSF NVMCON1, 7
    GOTO    start
    end
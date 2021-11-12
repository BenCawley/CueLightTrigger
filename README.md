# CueLightTrigger
A short embedded script to allow an arduino to interface with a tallyman tally system and trigger multiple camera mounted LEDs and monitor tally LEDs. The script consists of two sets of files, one for the trigger controller and one for the remotes, named accordingly. The trigger MCU is an arduino uno mounted in a control box to be placed in a central apparatus room, and the remote consists of an arduino mini pro mounted inside a Nuetrik Ethercon Coupler NE8FF, connected to each cat5 couplers pins. 

Currently the system supports up to 7 remotes, but is capable of 15 with modification. 

The basic premise of scripts is that three pins over a cat5 cable carry a binary channel selection via pulling each pin from default HIGH to LOW (MSB, TTL, up to four channels). Each remote connects to this bus and checks these channel pins, comparing them to a four channel dip switch attached to the MCU. If the channel selection pins are pulled to the channel that corresponds to the pin selected on the dip switch, the remote MCU will turn on a red LED and close a contact connected to two pins on the opposite connector (labelled OUT) to tigger a tally light on a 3rd party device (this is controller by pin 10 of the mini pro).

The full pinout is as follows:

Arduino Nano        Cat5         Pro Mini     Programming / Pass-Thru         LED        Dip Switch
    Pin            Pin            Pins                 Pins                  Pins          Pins
--------------------------------------------------------------------------------------------------
    GND             1              GND                 N/C
   (12V)            2              RAW                 N/C                          
     2              3             2/GND                GND
     3              4             3/RST                VCC
    N/C             5              RST                 RST
    N/C             6              10                  FWD*
    RST             7              RST                 RX
    13              8               9                  TX
                                    8                                        POS
                                   GND                                       GND            
                                    4                                                       CH1
                                    5                                                       CH2
                                    6                                                       CH3
                                    7                                                       CH4
                                   GND                                                      GND
                    


Raw pin is fed from a seperate 12VDC PSU in the control box with the Uno, as the mini pro has a voltage conver onboard to drop it down to 3.3v
FWD* = Forward Tally to a 3rd party device like the tally light of a camera monitor
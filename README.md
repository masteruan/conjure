# Read Me Conjure  
Arduino based control System 2018.  
## Pin Assign  
This section is for pin assignment. We use 16 output relay (22-38).  
The first value is for <b>pin assign</b> the second is for <b>open/relay off</b>  
the third is for <b>close/relay on</b>.

### Doors  
P1 Ingresso   `32   1   !`  
P2 Corridoio  `31   2   £`  
P3 Uscita     `30   3   =`  

### Lights  
L1 Bue        `36   n    N`  
L2 Sala       `37   o   O`  
L3 UV         `35   r    R`  
L4 Strobo     `34   h    H`  
L5 Cantina    `33   k    K`  

### Magnets  
C1 Tarocchi   `26   q    Q`  
C2 Santi      `27   w    W`  
C3 Finestra   `28   e    E`  
C4 Sedia      `29   d    D`  
C5 Arma cant  `25   p    P`  
C6 Orologio   `??   ?    ?`  
C7 Croci      `??   ?    ?`  

## Inputs  
Only two games for input.  
### Orologio  
Switch on the orologio by using `_orologio`  
in_orologio   `pin ??`  
### Mirror  
You can't switch on the mirror by command
in_mirror     `pin ??`  

## Animations  
> This sections is for animations  

- Lights in windows thunder effect  
Tempesta   `_tempesta`  

- Switch on <i>uv</i> and <i>faretto bue</i>  
UV fx   `_uvfx`  

## System  
> This sections is for control System  

Start Game `_startGame`  
- Start game and  close all doors switch off the lights;  
Preparation `_preparation`  
- Close all the doors all the games and swith ON the lights;  
Open All `_openAll`  
-  Open all the doors, the magnets and switch on the lights;  
Reset  `_reset`  
- Open all the doors and switch on the lights;  

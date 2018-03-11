# Read Me Conjure  

## Pin Assign  
This section is for pin assignment.  
The first value is for <b>pin assign>/b> the second is for <b>open/relay off</b>
the tirth is for <b>close/relay on</b>.

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

### Inputs  
in_orologio   `pin ??`  
in_mirror     `pin ??`  

## Animations  
Tempesta   `_tempesta`  
- Lights in windows thunder effect  
UV Sfx   `_uvfx`  
- Switch on uv and faretto bue  

### System  
> This sections is for control System  

Start Game `_startGame`  
- Start game and  close all doors switch off the lights  
Open All `_openAll`  
-  Open all the doors, the magnets and switch on the lights  
Reset  `_reset`  
- Open all the doors and switch on the lights  

System Calls
============

    mov eax, 0
    mov evx, 1
    int 0x80

Memory System Calls (0-1)
-------------------------

### 0 - malloc

Not implemented yet.

### 1 - free

Not implemented yet.

TTY System Calls (2-5)
----------------------

### 2 - cls

`eax`: 2

### 3 - putch

`eax`: 3
`ebx`: character

### 4 - set_foreground_color

`eax`: 4
`ebx`: color
`ecx`: brightness

### 5 - set_background_color

`eax`: 5
`ebx`: color
`ecx`: brightness

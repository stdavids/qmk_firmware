#pragma once

#ifdef RGB_MATRIX_ENABLE

    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN     // Sets the default mode, if none has been set
    #define RGB_MATRIX_DEFAULT_ON   true                            // Sets the default enabled state, if none has been set
    #define RGB_MATRIX_TIMEOUT      0                               // Number of milliseconds to wait until rgb automatically turns off
                                                                    //
    #define RGB_MATRIX_DEFAULT_VAL  RGB_MATRIX_MAXIMUM_BRIGHTNESS   // Sets the default brightness value, if none has been set
    #define RGB_MATRIX_DEFAULT_HUE  96                              // Sets the default hue value, if none has been set
    #define RGB_MATRIX_DEFAULT_SAT  192                             // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_DEFAULT_SPD  96                              // Sets the default animation speed, if none has been set

    ////////////////////////////////////////////////////////////
    //              INDEX VALUES FOR PER-KEY RGB
    ////////////////////////////////////////////////////////////

    #define RGB_IDX_ESC     0
    #define RGB_IDX_F1      6
    #define RGB_IDX_F2      12
    #define RGB_IDX_F3      18
    #define RGB_IDX_F4      23
    #define RGB_IDX_F5      28
    #define RGB_IDX_F6      34
    #define RGB_IDX_F7      39
    #define RGB_IDX_F8      44
    #define RGB_IDX_F9      50
    #define RGB_IDX_F10     56
    #define RGB_IDX_F11     61
    #define RGB_IDX_F12     66
    #define RGB_IDX_PRT     69

    #define RGB_IDX_TICK    1
    #define RGB_IDX_1       7
    #define RGB_IDX_2       13
    #define RGB_IDX_3       19
    #define RGB_IDX_4       24
    #define RGB_IDX_5       29
    #define RGB_IDX_6       35
    #define RGB_IDX_7       40
    #define RGB_IDX_8       45
    #define RGB_IDX_9       51
    #define RGB_IDX_0       57
    #define RGB_IDX_MINUS   62
    #define RGB_IDX_EQUAL   78
    #define RGB_IDX_BACKSPC 85

    #define RGB_IDX_TAB     2
    #define RGB_IDX_Q       8
    #define RGB_IDX_W       14
    #define RGB_IDX_E       20
    #define RGB_IDX_R       25
    #define RGB_IDX_T       30
    #define RGB_IDX_Y       36
    #define RGB_IDX_U       41
    #define RGB_IDX_I       46
    #define RGB_IDX_O       52
    #define RGB_IDX_P       5
    #define RGB_IDX_LBKT    63
    #define RGB_IDX_RBKT    89
    #define RGB_IDX_BSLASH  93

    #define RGB_IDX_CAPS    3
    #define RGB_IDX_A       9
    #define RGB_IDX_S       15
    #define RGB_IDX_D       21
    #define RGB_IDX_F       26
    #define RGB_IDX_G       31
    #define RGB_IDX_H       37
    #define RGB_IDX_J       42
    #define RGB_IDX_K       47
    #define RGB_IDX_L       53
    #define RGB_IDX_SEMI    59
    #define RGB_IDX_QUOTE   64
    #define RGB_IDX_ENTER   96

    #define RGB_IDX_LSHIFT  4
    #define RGB_IDX_Z       10
    #define RGB_IDX_X       16
    #define RGB_IDX_C       22
    #define RGB_IDX_V       27
    #define RGB_IDX_B       32
    #define RGB_IDX_N       38
    #define RGB_IDX_M       43
    #define RGB_IDX_COMMA   48
    #define RGB_IDX_PERIOD  54
    #define RGB_IDX_SLASH   60
    #define RGB_IDX_RSHIFT  90

    #define RGB_IDX_LCTRL   5
    #define RGB_IDX_LWIN    11
    #define RGB_IDX_LALT    17
    #define RGB_IDX_SPACE   33
    #define RGB_IDX_RALT    49
    #define RGB_IDX_FN      55
    #define RGB_IDX_RCTRL   65

    #define RGB_IDX_UP      94
    #define RGB_IDX_LEFT    95
    #define RGB_IDX_DOWN    97
    #define RGB_IDX_RIGHT   79

    #define RGB_IDX_DEL     72
    #define RGB_IDX_PGUP    75
    #define RGB_IDX_PGDN    86
    #define RGB_IDX_END     82

    #define RGB_IDX_LSIDE_0 67
    #define RGB_IDX_LSIDE_1 70
    #define RGB_IDX_LSIDE_2 73
    #define RGB_IDX_LSIDE_3 76
    #define RGB_IDX_LSIDE_4 80
    #define RGB_IDX_LSIDE_5 83
    #define RGB_IDX_LSIDE_6 87
    #define RGB_IDX_LSIDE_7 91

    #define RGB_IDX_RSIDE_0 68
    #define RGB_IDX_RSIDE_1 71
    #define RGB_IDX_RSIDE_2 74
    #define RGB_IDX_RSIDE_3 77
    #define RGB_IDX_RSIDE_4 81
    #define RGB_IDX_RSIDE_5 84
    #define RGB_IDX_RSIDE_6 88
    #define RGB_IDX_RSIDE_7 92

#endif // RGB_MATRIX_ENABLE

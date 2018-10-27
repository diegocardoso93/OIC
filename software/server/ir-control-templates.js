
let IRcontrols = [{
    name: 'tv',
    button: {
        power    : '', // '0x20DF10EF',
        caption  : '',
        help     : '',
        search   : '',
        home     : '',
        n1       : '',
        n2       : '',
        n3       : '',
        n4       : '',
        n5       : '',
        n6       : '',
        n7       : '',
        n8       : '',
        n9       : '',
        list     : '',
        n0       : '',
        flashbk  : '',
        volp     : '',
        chp      : '',
        fav      : '',
        info     : '',
        mute     : '',
        volm     : '',
        chm      : '',
        settings : '',
        up       : '',
        livezoom : '',
        ok       : '',
        right    : '',
        back     : '',
        down     : '',
        exit     : '',
        sap      : '',
        sleep    : '',
        stop     : '',
        rewind   : '',
        play     : '',
        pause    : '',
        forward  : '',
        point1   : '',
        point2   : '',
        point3   : '',
        point4   : ''
    },
    voice: [
        {
            btn: 'power',
            cmd: 'ligar tv'
        },
        {
            btn: 'caption',
            cmd: ''
        },
        {
            btn: 'help',
            cmd: ''
        },
        {
            btn: 'search',
            cmd: ''
        },
        {
            btn: 'home',
            cmd: ''
        },
        {
            btn: 'n1',
            cmd: ''
        },
        {
            btn: 'n2',
            cmd: ''
        },
        {
            btn: 'n3',
            cmd: ''
        },
        {
            btn: 'n4',
            cmd: ''
        },
        {
            btn: 'n5',
            cmd: ''
        },
        {
            btn: 'n6',
            cmd: ''
        },
        {
            btn: 'n7',
            cmd: ''
        },
        {
            btn: 'n8',
            cmd: ''
        },
        {
            btn: 'n9',
            cmd: ''
        },
        {
            btn: 'list',
            cmd: ''
        },
        {
            btn: 'n0',
            cmd: ''
        },
        {
            btn: 'flashbk',
            cmd: ''
        },
        {
            btn: 'volp',
            cmd: ''
        },
        {
            btn: 'chp',
            cmd: ''
        },
        {
            btn: 'fav',
            cmd: ''
        },
        {
            btn: 'info',
            cmd: ''
        },
        {
            btn: 'mute',
            cmd: ''
        },
        {
            btn: 'volm',
            cmd: ''
        },
        {
            btn: 'chm',
            cmd: ''
        },
        {
            btn: 'settings',
            cmd: ''
        },
        {
            btn: 'up',
            cmd: ''
        },
        {
            btn: 'livezoom',
            cmd: ''
        },
        {
            btn: 'ok',
            cmd: ''
        },
        {
            btn: 'right',
            cmd: ''
        },
        {
            btn: 'back',
            cmd: ''
        },
        {
            btn: 'down',
            cmd: ''
        },
        {
            btn: 'exit',
            cmd: ''
        },
        {
            btn: 'sap',
            cmd: ''
        },
        {
            btn: 'sleep',
            cmd: ''
        },
        {
            btn: 'stop',
            cmd: ''
        },
        {
            btn: 'rewind',
            cmd: ''
        },
        {
            btn: 'play',
            cmd: ''
        },
        {
            btn: 'pause',
            cmd: ''
        },
        {
            btn: 'forward',
            cmd: ''
        },
        {
            btn: 'point1',
            cmd: ''
        },
        {
            btn: 'point2',
            cmd: ''
        },
        {
            btn: 'point3',
            cmd: ''
        },
        {
            btn: 'point4',
            cmd: ''
        }
    ],
    cfgKey: 'cfgTvControl' // mongodb cfgKey config name
},
{
    name: 'split',
    button: {
        power  : '',
        mode   : '',
        sleep  : '',
        up     : '',
        fan    : '',
        timer  : '',
        down   : '',
        swing  : ''
    },
    voice: [
        {
            btn: 'power',
            cmd: ''
        },
        {
            btn: 'mode',
            cmd: ''
        },
        {
            btn: 'sleep',
            cmd: ''
        },
        {
            btn: 'up',
            cmd: ''
        },
        {
            btn: 'fan',
            cmd: ''
        },
        {
            btn: 'timer',
            cmd: ''
        },
        {
            btn: 'down',
            cmd: ''
        },
        {
            btn: 'swing',
            cmd: ''
        }
    ],
    cfgKey: 'cfgSplitControl'
},
{
    name: 'light',
    button: {
        brighthness_70  : '',
        brighthness_50  : '',
        brighthness_0   : '',
        brighthness_100 : '',
        r               : '',
        g               : '',
        b               : '',
        w               : '',
        c1              : '',
        c2              : '',
        c3              : '',
        flash           : '',
        c4              : '',
        c5              : '',
        c6              : '',
        strobe          : '',
        c7              : '',
        c8              : '',
        c9              : '',
        smooth          : '',
        c10             : '',
        c11             : '',
        c12             : ''
    },
    voice: [
        {
            btn: 'brighthness_70',
            cmd: ''
        },
        {
            btn: 'brighthness_50',
            cmd: ''
        },
        {
            btn: 'brighthness_0',
            cmd: ''
        },
        {
            btn: 'brighthness_100',
            cmd: ''
        },
        {
            btn: 'r',
            cmd: ''
        },
        {
            btn: 'g',
            cmd: ''
        },
        {
            btn: 'b',
            cmd: ''
        },
        {
            btn: 'w',
            cmd: ''
        },
        {
            btn: 'c1',
            cmd: ''
        },
        {
            btn: 'c2',
            cmd: ''
        },
        {
            btn: 'c3',
            cmd: ''
        },
        {
            btn: 'flash',
            cmd: ''
        },
        {
            btn: 'c4',
            cmd: ''
        },
        {
            btn: 'c5',
            cmd: ''
        },
        {
            btn: 'c6',
            cmd: ''
        },
        {
            btn: 'strobe',
            cmd: ''
        },
        {
            btn: 'c7',
            cmd: ''
        },
        {
            btn: 'c8',
            cmd: ''
        },
        {
            btn: 'c9',
            cmd: ''
        },
        {
            btn: 'smooth',
            cmd: ''
        },
        {
            btn: 'c10',
            cmd: ''
        },
        {
            btn: 'c11',
            cmd: ''
        },
        {
            btn: 'c12',
            cmd: ''
        }
    ],
    cfgKey: 'cfgLightControl'
},
{
    name: 'receptor-tv',
    button: {
        power    : '',
        power_tv : '',
        set_tv   : '',
        tv_in    : '',
        volm_tv  : '',
        volp_tv  : '',
        setup    : '',
        app      : '',
        volm     : '',
        volp     : '',
        home     : '',
        up       : '',
        repeate  : '',
        left     : '',
        ok       : '',
        right    : '',
        keyboard : '',
        down     : '',
        mouse    : '',
        n1       : '',
        n2       : '',
        n3       : '',
        n4       : '',
        n5       : '',
        n6       : '',
        n7       : '',
        n8       : '',
        n9       : '',
        mute     : '',
        n0       : '',
        close    : ''
    },
    voice: [
        {
            btn: 'power',
            cmd: ''
        },
        {
            btn: 'power_tv',
            cmd: ''
        },
        {
            btn: 'set_tv',
            cmd: ''
        },
        {
            btn: 'tv_in',
            cmd: ''
        },
        {
            btn: 'volm_tv',
            cmd: ''
        },
        {
            btn: 'volp_tv',
            cmd: ''
        },
        {
            btn: 'setup',
            cmd: ''
        },
        {
            btn: 'app',
            cmd: ''
        },
        {
            btn: 'volm',
            cmd: ''
        },
        {
            btn: 'volp',
            cmd: ''
        },
        {
            btn: 'home',
            cmd: ''
        },
        {
            btn: 'up',
            cmd: ''
        },
        {
            btn: 'repeate',
            cmd: ''
        },
        {
            btn: 'left',
            cmd: ''
        },
        {
            btn: 'ok',
            cmd: ''
        },
        {
            btn: 'right',
            cmd: ''
        },
        {
            btn: 'keyboard',
            cmd: ''
        },
        {
            btn: 'down',
            cmd: ''
        },
        {
            btn: 'mouse',
            cmd: ''
        },
        {
            btn: 'n1',
            cmd: ''
        },
        {
            btn: 'n2',
            cmd: ''
        },
        {
            btn: 'n3',
            cmd: ''
        },
        {
            btn: 'n4',
            cmd: ''
        },
        {
            btn: 'n5',
            cmd: ''
        },
        {
            btn: 'n6',
            cmd: ''
        },
        {
            btn: 'n7',
            cmd: ''
        },
        {
            btn: 'n8',
            cmd: ''
        },
        {
            btn: 'n9',
            cmd: ''
        },
        {
            btn: 'mute',
            cmd: ''
        },
        {
            btn: 'n0',
            cmd: ''
        },
        {
            btn: 'close',
            cmd: ''
        }
    ],
    cfgKey: 'cfgReceptorTvControl'
}]

module.exports = IRcontrols


let IRcontrols = {

    tv: {
        button: {
            power    : '0x20DF10EF',
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
        document: 'cfgTvControl' // mongodb document config name
    },

    split: {
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
        document: 'cfgSplitControl'
    },

    light: {
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
        document: 'cfgLightControl'
    }
}

module.exports = IRcontrols
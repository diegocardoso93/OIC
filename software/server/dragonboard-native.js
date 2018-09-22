const { spawn } = require('child_process');

class DragonBoardNative {

  constructor () {
    this.programs = {
      temperature: {
        name: 'temperature',
        path: '../../hardware/dragonboard/temperature/main',
        msg: null
      }
    }
  }

  call (name) {
    if (!this.programs[name]) {
      throw new Error('${name} not supported yet.')
    } else {
      let program = this._start(this.programs[name])
      this._registerProgramListeners(program, name)
    }
    return this.programs[name].msg
  }

  _start (programObj) {
    return spawn('sudo', [programObj.path])
  }

  _registerProgramListeners (program, name) {
    this.programs[name].msg = new Promise((resolve, reject) => {
      program.stdout.on('data', (data) => {
        resolve(data)
      })
      program.stderr.on('data', (data) => {
        reject(data)
      })
      program.on('exit', function (code, signal) {
        resolve({code: code, signal: signal})
      })
    })
  }
}

/* EXAMPLE USAGE
let dbn = new DragonBoardNative()
dbn.call('temperature')
   .then((data) => {
     console.log(data.toString('utf8'))
   })
*/
module.exports = new DragonBoardNative()

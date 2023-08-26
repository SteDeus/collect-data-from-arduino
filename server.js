const SerialPort = require('serialport').SerialPort;
const Readline = require('@serialport/parser-readline');
const port = new SerialPort({ path: 'COM4', baudRate: 9600 }); // Cambia 'COM4' con la porta seriale corretta

const parser = port.pipe(new Readline.ReadlineParser({ delimiter: '\n' }));

port.on('open', () => {
  console.log('Port opened');

  parser.on('data', (data) => {
    if (data.startsWith('DATA,')) {
      const dataArray = data.split(',');
      const temperature = parseFloat(dataArray[1]);
      const humidity = parseFloat(dataArray[2]);
      console.log(`Temperature: ${temperature} deg. C, Humidity: ${humidity}%`);

      // Chiamata a DB per passare dati
    }
  });
});

#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, { json: true }, async (err, res, body) => {
  if (err) { return console.log(err); }
  const charurls = body.characters;
  for (const charindx in charurls) {
    const data = await new Promise((resolve, reject) => {
      request(charurls[charindx], { json: true }, function (er, res, body) {
        if (er) { reject(err); } else { resolve(body.name); }
      });
    });
    console.log(data);
  }
});

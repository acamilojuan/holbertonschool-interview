#!/usr/bin/node
// prints all characters of a Star Wars movie
const request = require('request');

function catchMainData (indexPage) {
  const firstUrl = `https://swapi-api.hbtn.io/api/films/${indexPage}/`;
  return new Promise((resolve, reject) => {
    request(firstUrl, function (error, res, body) {
      if (!error && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
}

function catchPeople (character) {
  return new Promise((resolve, reject) => {
    request(character, (error, res, body) => {
      if (!error && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
}

async function main () {
  const argv = +process.argv[2];
  const data = await catchMainData(argv);
  const charactersFilms = JSON.parse(data).characters;

  for (const i in charactersFilms) {
    const people = await catchPeople(charactersFilms[i]);
    console.log(JSON.parse(people).name);
  }
}

main();

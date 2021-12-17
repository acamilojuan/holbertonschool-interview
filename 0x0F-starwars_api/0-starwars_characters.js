#!/usr/bin/node

const request = require('request');

const filmId = process.argv[2];
let url = 'https://swapi-api.hbtn.io/api/films/';

url = url + filmId + '/';

request(url, (error, response, body) => {
  // Printing the error if occurred
  if (error) console.log(error);

  // Printing status code
  // console.log(response.statusCode);

  // Printing characters from body in JSON format
  const Characters = JSON.parse(body).characters;

  // Extract new url for each character to make a new request for their name
  for (const people of Characters) {
    request(people, (error, response, body) => {
      // Printing the error if occurred
      if (error) console.log(error);

      // Printing status code
      // console.log(response.statusCode);

      // Printing character name
      console.log(JSON.parse(body).name);
    });
  }
});

#!/usr/bin/node

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

function getData (url) {
    return new Promise((resolve, reject) => {
        request(url, (err, response, body) => {
            if (err) reject(err);
            resolve(JSON.parse(body));
        });
    });
}

async function getNames () {
    const res = await getData(url);
    res.characters.forEach(async function (character) {
        const chrtr = await getData(character);
        console.log(chrtr.name);
    });
}

getNames();

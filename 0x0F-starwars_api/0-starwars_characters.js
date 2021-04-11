#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

request(`https://swapi-api.hbtn.io/api/films/${movieId}/`, (_, _0, body) => {
  const characters = JSON.parse(body).characters;
  characters.forEach(char => {
    request(char, (_, _0, body) => {
      console.log(JSON.parse(body).name);
    });
  });
});

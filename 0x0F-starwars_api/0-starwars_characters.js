#!/usr/bin/node
const { rejects } = require('assert');
const request = require('request');

const movieId = process.argv[2];

const displayNamesAsync = async char => {
  return new Promise((resolve, reject) => {
    request(char, (error, _0, body) => {
      if (body) {
        resolve(JSON.parse(body).name);
      } else {
        reject(error);
      }
    });
  });
};

request(`https://swapi-api.hbtn.io/api/films/${movieId}/`, async (_, _0, body) => {
  const characters = JSON.parse(body).characters;
  for (const char of characters) {
    console.log(await displayNamesAsync(char));
  }
});

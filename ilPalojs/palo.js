const request = require("request");
const opn = require("opn");
const puppeteer = require("puppeteer");

// Define the IP address and port of the Arduino inside the url
const options = {
  url: "http://yourIP:80/motion",
  method: "GET",
};
const url = "https://stackoverflow.com/";
var tabExist = false;

setInterval(() => {
  (async () => {
    const browser = await puppeteer.launch();
    const pages = await browser.pages();
    tabExist = false;

    for (const page of pages) {
      if (page.url() === "https://stackoverflow.com/") {
        tabExist = true;
        break;
      }
    }
    console.log("TabExist: " + tabExist);
    await browser.close();
  })();

  request(options, (error, response, body) => {
    if (!error && response.statusCode == 200) {
      const data = body.trim();
      console.log("Incoming message: " + body);
      if (data === "1" && !tabExist) {
        console.log("Motion detected, opening browser tab");
        opn(url);
        tabExist = true;
      }
    } else {
      console.log(error);
    }
  });
}, 300); // Make the GET request every 300 ms

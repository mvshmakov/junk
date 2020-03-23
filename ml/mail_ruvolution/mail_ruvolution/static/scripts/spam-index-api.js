function spamIndex(text, author) {
    return new Promise((resolve, reject) => {
        function reqListener() {
            const answer = this.responseText;
            resolve(answer);
        }

        const oReq = new XMLHttpRequest();
        oReq.addEventListener("load", reqListener);
        oReq.open("GET", "http://my.smart-pot.ru/spam_test?text=" + text + "&author=" + author);
        oReq.send();
    });
}

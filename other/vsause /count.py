import json
from pymystem3 import Mystem
import nltk
import re
from codecs import open

m = Mystem()
regexp_pattern = '.!?,;:\'\"/\\'
stop_words = nltk.corpus.stopwords.words('english')

lemmas = []

q = []

with open('./', 'r', encoding='utf-8') as f:
    s = f.read()
    s = re.sub("'", '"', s)
    messages = json.loads(s)

    for message in messages:
        subject_regexped = " ".join(
            [n for n in re.findall("[A-Za-z]+", message["subject"].lower()) if n not in stop_words])
        snippet_regexped = " ".join(
            [n for n in re.findall("[A-Za-z]+", message["snippet"].lower()) if n not in stop_words])

        subject = ''.join(m.lemmatize(subject_regexped))
        snippet = ''.join(m.lemmatize(snippet_regexped))

        email = message["correspondents"]["from"][0]["email"]
        message_id = message["id"]

        message_stringified = message_id + ' |text ' + subject + ' ' + snippet + ' |author ' + email
        lemmas.append(message_stringified)

with open('output/' + filename.split("/")[-1].split(".")[0] + ".txt", 'w', encoding='utf-8') as f:
    f.write('\n'.join(lemmas))

q += lemmas

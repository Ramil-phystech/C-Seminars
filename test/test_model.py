import joblib
import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
import numpy as np

nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('stopwords')

path_to_vectorizer = "models/vectorizers/multi_RandomForest(data_6)_vectorizer.joblib"
path_to_model = "models/multi_RandomForest(data_6).sav"

stop_words = set(stopwords.words('russian'))
vectorizer = joblib.load(path_to_vectorizer)

p = ['Anekdot', 'Bolls_and_Cows', 'Calculator', 'Exchange_rate',
     'Facts_of_cats', 'Goodbye', 'Hello', 'Music', 'Time', 'Weather', "stop_game"]

index = {p[i]: i for i in range(len(p))}


def preprocess(text):
    tokens = word_tokenize(text.lower())
    filtered_tokens = [word for word in tokens if word.isalnum() and (word not in stop_words or word.lower()
                                                                      in 'нет не ни не да ага не-а')]
    return ' '.join(filtered_tokens)


model = joblib.load(open(path_to_model, 'rb'))
print(model.get_params())

MIN_PROBA = 60

while True:
    s = preprocess(input())
    print(s)
    s_processed = vectorizer.transform([s])
    predict = np.array([x[0][1] * 100 for x in model.predict_proba(s_processed)])
    probs = [i for i in range(len(predict)) if predict[i] >= MIN_PROBA]
    if len(probs) == 2 and (index['Hello'] in probs or index['Goodbye'] in probs):
        if index['Hello'] in probs:
            probs.remove(index['Hello'])
        else:
            probs.remove(index['Goodbye'])
        print(fr'Предсказание: {p[probs[0]]}. Вероятность: {predict[probs[0]]}')

    elif len(probs) > 1 or len(probs) == 0:
        print('Не пон', probs)
        print("Предсказания и вероятности: ")
        print(*zip(p, predict))
    else:
        print(fr'Предсказание: {p[probs[0]]}. Вероятность: {predict[probs[0]]}')
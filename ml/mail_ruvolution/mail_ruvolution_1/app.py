# -*- coding: utf-8 -*-
import os
from codecs import open
from sqlalchemy import func
from flask_sqlalchemy import SQLAlchemy
from flask import Flask, request, render_template, url_for, json, session, redirect

app = Flask(__name__)

basedir = os.path.abspath(os.path.dirname(__file__))
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(basedir, 'main.db')
db = SQLAlchemy(app)

base_url = "https://domain/api/v1/"
token = "749f312eca3976d786b0c79c73de7119020c5fb537363830"

email = "smartmail_team5@mail.ru"
test_email = "info@ru.mailstudiomoderna.com"
password = "1"

dataForSearch = ['hello','world','python','hello world']
db_cols = ['id', 'name', 'email', 'subject', 'snippet', 'date',
		   'w1', 'w2', 'w3', 'class1', 'class2', 'class3']

class Mailbox(db.Model):
	id = db.Column(db.Integer, primary_key=True)
	message_id = db.Column(db.String(255))
	name = db.Column(db.String(255))
	email = db.Column(db.String(255))
	subject = db.Column(db.String(255))
	snippet = db.Column(db.String(255))
	date = db.Column(db.Integer)
	w1 = db.Column(db.Float)
	w2 = db.Column(db.Float)
	w3 = db.Column(db.Float)
	class1 = db.Column(db.String(255))
	class2 = db.Column(db.String(255))
	class3 = db.Column(db.String(255))

@app.route("/")
def index():
	if not session.get('login'):
		return redirect("/login")
	try:
		mailbox = Mailbox.query.filter_by(email=session['login']).all()
		print(mailbox)
	except:
		return redirect("/loader")
	return render_template("index.html")

@app.route("/main")
def main():
	if not session.get('login'):
		return redirect("/login")
	try:
		mailbox = Mailbox.query.filter_by(email=session['login']).all()
		print(mailbox)
	except:
		return redirect("loader")
	return render_template("main.html", title='Main', dataForSearch=dataForSearch)

@app.route("/login", methods=["GET","POST"])
def login():
	if session.get('login'):
		return redirect("/main")
	if request.method == "GET":
		return render_template("login.html", title='Login')
	if request.form['password'] == password and str(request.form['login'] + request.form['domain']) == email:
		session['login'] = str(request.form['login'] + request.form['domain'])
		return redirect("/main")
	else:
		return render_template("login.html", title='Wrong password')

@app.route("/logout", methods=["POST"])
def logout():
	if not session.get('login'):
		return redirect("/login")
	session['login'] = None
	return redirect("/login")

@app.route("/loader", methods=["GET", "POST"])
def loader():
	if not session.get('login'):
		return redirect("/login")
	return render_template("loader.html", title='Loading...')

@app.route("/load_status", methods=["POST"])
def load_status():
	if not session.get('login'):
		return redirect("/login")
	try:
		mailbox = Mailbox.query.filter_by(email=session['login']).all()
		return redirect("/main")
	except:
		return json.dumps({ "status": "working" }, ensure_ascii=False)

@app.route("/load_data", methods=["GET", "POST"])
def load_data():
	if not session.get('login'):
		return redirect("/login")
	mailbox = Mailbox.query.filter_by(email=session['login']).all()
	if mailbox:
		return redirect("/main")
	else:
		with open('./result.json', 'r', encoding='utf-8') as f:
			data_json = json.load(f)
			for mail_json in data_json:
				print(mail_json['id'], mail_json['name'], mail_json['email'])
				mailbox = Mailbox( \
					message_id = mail_json['id'], \
					name = mail_json['name'], \
					email = mail_json['email'], \
					subject = mail_json['subject'], \
					snippet = mail_json['snippet'], \
					date = mail_json['date'], \
					w1 = mail_json['w1'], \
					w2 = mail_json['w2'], \
					w3 = mail_json['w3'], \
					class1 = mail_json['class1'], \
					class2 = mail_json['class2'], \
					class3 = mail_json['class3'])
				db.session.add(mailbox)
				db.session.commit()
			return redirect("/main")

@app.route("/search_ajax")
def search_ajax():
	req = request.args
	req_query = Mailbox.query.with_entities(Mailbox.email, func.count(Mailbox.email)).group_by(Mailbox.email).all()

	return json.dumps(dict(req_query), ensure_ascii=False)

@app.route("/get_email_children")
def get_email_children():
	req = request.args

	req_query = Mailbox.query.filter(Mailbox.email == req['email']).all()
	req_obj = [{col: getattr(single, col) for col in db_cols} for single in req_query]

	return json.dumps(req_obj, ensure_ascii=False)

@app.route("/get_class_children")
def get_class_children():
	req = request.args

	req_query = Mailbox.query.filter(Mailbox.class1 == req['class1']).all()
	req_obj = [{col: getattr(single, col) for col in db_cols} for single in req_query]

	return json.dumps(req_obj, ensure_ascii=False)

@app.route("/get_snippet")
def get_snippet():
	req = request.args

	req_query = Mailbox.query.filter(Mailbox.message_id == req['message_id']).all()
	req_obj = [{col: getattr(single, col) for col in db_cols} for single in req_query]

	return json.dumps(req_obj, ensure_ascii=False)

@app.route("/get_mail")
def get_mail():
	req = request.args

	link = base_url + "messages/message?access_token=" + token + "&email=" + email + "&" + req["id"]
	resp = requests.get(link).text

	return json.dumps(resp, ensure_ascii=False)

@app.route("/get_all_categories")
def get_all_categories():
	req_query = Mailbox.query.with_entities(Mailbox.class1, func.count(Mailbox.class1)).group_by(Mailbox.class1).all()

	return json.dumps(dict(req_query), ensure_ascii=False)

@app.after_request
def after_request(response):
    response.headers.add('Access-Control-Allow-Origin', '*')
    response.headers.add('Access-Control-Allow-Headers', 'Content-Type,Authorization')
    response.headers.add('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE,OPTIONS')
    return response

if __name__ == '__main__':
	app.secret_key = os.urandom(12)
	app.run(debug=True)

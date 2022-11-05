from flask import Flask
from flask_sqlalchemy import SQLAlchemy
import redis
from flask_cors import CORS

app = Flask(__name__)


app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///C:/Users/Grzegorz/Documents/Porg/hakaton/server/db.db'
app.config['SECRET_KEY'] = '6be575743c714c0250e548de'
app.config['SESSION_REDIS'] = redis.from_url("redis://127.0.0.1:6379")

db = SQLAlchemy(app)
CORS(app, supports_credentials=True)

with app.app_context():
    db.create_all()


from server import routes 
from flask import Flask, render_template, url_for
 
app = Flask(__name__)      
app.config.from_object('config')

@app.route('/')
def home():
  return render_template('home.html')

@app.route('/team')
def team():
	return render_template('team.html')
 
if __name__ == '__main__':
  app.run(debug=True)
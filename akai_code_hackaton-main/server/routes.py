from server import app, db
from flask import jsonify, request


class Score(db.Model):
    
    id = db.Column(db.Integer(), primary_key=True, unique=True)
    username = db.Column(db.Text(), nullable=False, unique=True)
    game1_score = db.Column(db.Text(), nullable=False)
    game2_score = db.Column(db.Text(), nullable=False)
    game3_score = db.Column(db.Text(), nullable=False)
    game4_score = db.Column(db.Text(), nullable=False) 
    

    
@app.route('/score', methods = ['POST', 'GET'])
def home():
    
    scores = []
    score_dict = {'username':str,'game1':str,'game2':str,'game3': str, 'game4':str}
    with open(r'C:\Users\Grzegorz\Documents\Porg\hakaton\server\scores.txt' , encoding='iso8859-2') as f:
        lines = f.readlines()
        
        count = sum(1 for _ in lines)
        print(count)
        player_num = int(count/4)
        
        data = list(lines)
        
        for i in range(player_num):
            scores.append(score_dict)
            
        i = 0
        
        player_ = ''
        
        for i in range(count):
    
            
            if player_ != data[i].split()[0]:
                player_ = data[i].split()[0]
                
                
            
            if i == 0 or i%4 == 0:
                user = player_
                g1 = data[i].split()[1]
                g2 = data[i+1].split()[1]
                g3 = data[i+2].split()[1]
                g4 = data[i+3].split()[1]
                
                user_exists = Score.query.filter_by(username=user).first() is not None
                
                if user_exists:
                    
                    prev_g1 = Score.query.filter_by(username=user).first()
                    prev_g2 = Score.query.filter_by(username=user).first()
                    prev_g3 = Score.query.filter_by(username=user).first()
                    prev_g4 = Score.query.filter_by(username=user).first()
                    
                    if int(g1)>int(prev_g1.game1_score):
                        prev_g1.game1_score = g1
                    if int(g2)>int(prev_g2.game2_score):
                        prev_g2.game2_score = g2
                    if int(g3)>int(prev_g3.game3_score):
                        prev_g3.game3_score = g3
                    if int(g4)>int(prev_g4.game4_score):
                        prev_g4.game4_score = g4
                    
                    
                    db.session.commit()
                else:            
                    new_score = Score(username = user ,game1_score = g1, 
                                    game2_score = g2,  game3_score = g3,
                                    game4_score = g4)
                    
                    print(new_score)
                    db.session.add(new_score)
                    db.session.commit()
                    
    db_scores = Score.query.all()
    scores_ = []
    
    for item in db_scores:
        
        score = {
            "id": item.id,
            "username": item.username,
            "game1": item.game1_score,
            "game2": item.game2_score,
            "game3": item.game3_score,
            "game4": item.game4_score
        }
        
        scores_.append(score)

    print(scores_)
    return jsonify(scores_)
                 
        
    
    
    
        



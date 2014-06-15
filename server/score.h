#ifndef SCORE_H
#define SCORE_H

class Score
{
public:
    Score();
    Score(int i);
    void addKill();
    void addDeath();
    void setID(int i);
private:
    int kills;
    int deaths;
    int tankID;
};

#endif // SCORE_H

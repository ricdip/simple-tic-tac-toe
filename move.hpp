class Move {
   private:
    int* position;
    int score;

   public:
    Move() {}
    Move(int* p) { position = p; }
    Move(int* p, int s) {
        position = p;
        score = s;
    }
    int getScore() const { return score; }
    void setScore(int s) { score = s; }
    void setPosition(int p[2]) {
        position[0] = p[0];
        position[1] = p[1];
    }
    int* getPosition() const { return position; }
};

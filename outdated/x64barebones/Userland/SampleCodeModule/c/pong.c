#include <pong.h>

#define WIN_CONDITION 3
#define MOVEMENT 8
#define SPEED 4

void drawScreen(){
    for(int i = 0; i < WIDTH; i++){
        putPixel(RENGLON * 4 - 6, i, GREY);
        putPixel(RENGLON * 4 - 5, i, GREY);
        putPixel(HEIGHT - RENGLON + 4, i, GREY);
        putPixel(HEIGHT - RENGLON + 5, i, GREY);
    }
    for(int i = RENGLON * 4 - 4; i < HEIGHT - RENGLON + 4; i++){
        putPixel(i, WIDTH / 2, GREY);
        putPixel(i, (WIDTH / 2) + 1, GREY);
    }
}

void drawObjects(int xFrom, int xTo, int yFrom, int yTo, int color){
    for(int i = yFrom; i < yTo; i++){
        for(int j = xFrom; j < xTo; j++){
            putPixel(i, j, color);
        }
    }
}

void drawPaddle(int x, int y, int player){
    if(player == 1){
        drawObjects(x, x + PADDLE_WIDTH, y, y + PADDLE_HEIGHT, ROSE);
    }else{
        drawObjects(x, x + PADDLE_WIDTH, y, y + PADDLE_HEIGHT, SEA_GREEN);
    }
}
void undrawPaddle(int x, int y){
    drawObjects(x, x + PADDLE_WIDTH, y, y + PADDLE_HEIGHT, BLACK);
}

void drawBall(int x, int y){
    drawObjects(x, x + BALL_RADIUS, y, y + BALL_RADIUS, WHITE);
}
void undrawBall(int x, int y){
    drawObjects(x, x + BALL_RADIUS, y, y + BALL_RADIUS, BLACK);
}

void menuPong(){
    clearScreen();
    drawScreen();
    printIn("Welcome to the first game ever PONG!", 0, (WIDTH / 2) - 18 * LETRA, WHITE);
    printIn("The first player to reach 10 points wins", RENGLON * 1, (WIDTH / 2) - 20 * LETRA, WHITE);
    printIn("Player 1 moves with 'W' and 'S'", RENGLON * 2, 0, ROSE);
    printIn("Player 2 moves with 'O' and 'L'", RENGLON * 2, WIDTH - 32 * LETRA, SEA_GREEN);
    printIn("Press 'SPACE' key to start", HEIGHT - 1, 0, WHITE);
    printIn("Press 'B' to return ", HEIGHT - 1, WIDTH - 20 * LETRA, WHITE);
    char c;
    while((c = getChar()) != 'b' && c != 'B'){
        if(c == ' '){
            clearScreen();
            playPong();
            break;
        }
    }
    return;
}

int p1Y, p2Y;
int ballX, ballY;
int score1 = 0, score2 = 0;
int xDirection, yDirection;
int score;

void setup(int reset){
    if(reset == 0){
        ballX = (WIDTH / 2) - 1; 
        ballY = HEIGHT / 2 - 2;
        p1Y = HEIGHT / 2;
        p2Y = HEIGHT / 2;
        score = 0;
        drawPaddle(PADDLE1_X_POSITION, p1Y, 1);
        drawPaddle(PADDLE2_X_POSITION, p2Y, 2);
        if(score1 >= score2){
            xDirection = SPEED; //-1 va a la izquierda y 1 a la derecha
            yDirection = -SPEED;
        }else{
            xDirection = -SPEED;
            yDirection = -SPEED;
        }
    }else{
        score1 = 0;
        score2 = 0;
    }
}

void playPong(){
    char points1[3] = {0};
    char points2[3] = {0};
    setup(0);
    printIn("Player 1 points: ", RENGLON * 2, 0, WHITE);
    printIn("Player 2 points: ", RENGLON * 2, WIDTH - 19 * LETRA, WHITE);
    printIn(itoa(score1, points1), RENGLON * 2, 18 * LETRA, ROSE);
    printIn(itoa(score2, points2), RENGLON * 2, WIDTH - 2 * LETRA, SEA_GREEN);
    printIn("Press 'B' to return ", HEIGHT - 1, WIDTH - 20 * LETRA, WHITE);
    drawScreen();
    drawPaddle(PADDLE1_X_POSITION, p1Y, 1);
    drawPaddle(PADDLE2_X_POSITION, p2Y, 2);
    drawBall(ballX, ballY);
    char c;
    while((c = getChar()) != 'b' && c != 'B' && (score1 < WIN_CONDITION && score2 < WIN_CONDITION)){
        if(score){
            beep(440);
            hold(20);
            stop();
            printIn(itoa(score1, points1), RENGLON * 2, 18 * LETRA, ROSE);
            printIn(itoa(score2, points2), RENGLON * 2, WIDTH - 2 * LETRA, SEA_GREEN);
            setup(0);
        }
        moveBall();
        movePlayer(c);
    }
    if( c == 'b' || c == 'B'){
        return;
    }
    clearScreen();
    if(score1 == WIN_CONDITION){
        printIn("Player 1 wins!", HEIGHT / 2, (WIDTH / 2) - 7 * LETRA, ROSE);
    }else{
        printIn("Player 2 wins!", HEIGHT / 2, (WIDTH / 2) - 7 * LETRA, SEA_GREEN);
    }
    hold(500);
    setup(1);
    menuPong();
}

void movePlayer(char c){
        if(c == 'w' || c == 'W' ){
            if(p1Y > TOP_BOUNDARY){
                undrawPaddle(PADDLE1_X_POSITION, p1Y);
                p1Y -= MOVEMENT;
                drawPaddle(PADDLE1_X_POSITION, p1Y, 1);
            }
        }
        if(c == 's' || c == 'S' ){
            if(p1Y + PADDLE_HEIGHT <= BOTTOM_BOUNDARY){
                undrawPaddle(PADDLE1_X_POSITION, p1Y);
                p1Y += MOVEMENT;
                drawPaddle(PADDLE1_X_POSITION, p1Y, 1);
            }
        }
        if(c == 'o' || c == 'O'){
            if(p2Y > TOP_BOUNDARY){
                undrawPaddle(PADDLE2_X_POSITION, p2Y);
                p2Y -= MOVEMENT;
                drawPaddle(PADDLE2_X_POSITION, p2Y, 2);
            }
        }
        if(c == 'l' || c == 'L'){
            if(p2Y + PADDLE_HEIGHT <= BOTTOM_BOUNDARY){
                undrawPaddle(PADDLE2_X_POSITION, p2Y);
                p2Y += MOVEMENT;
                drawPaddle(PADDLE2_X_POSITION, p2Y, 2);
            }
        }
        return;
    }

void moveBall() {
    hold(18);
    
    undrawBall(ballX, ballY);

    ballX += xDirection;

    //Chequeo de colisiones con Paddles
    if (ballX == PADDLE1_X_POSITION + PADDLE_WIDTH && ballY >= p1Y && ballY <= p1Y + PADDLE_HEIGHT) {
        if(ballY >= p1Y + PADDLE_HEIGHT / 2 - 2 && ballY <= p1Y + PADDLE_HEIGHT / 2 + 2){
            yDirection = 0;
            xDirection = SPEED;
        }else if(yDirection == 0){
            yDirection = -SPEED;
            xDirection = SPEED;
        }else{
            xDirection = SPEED;
        }
    } else if (ballX == PADDLE2_X_POSITION - BALL_RADIUS && ballY >= p2Y && ballY <= p2Y + PADDLE_HEIGHT) {
        if(ballY >= p2Y + PADDLE_HEIGHT / 2 - 2 && ballY <= p2Y + PADDLE_HEIGHT / 2 + 2){
            yDirection = 0;
            xDirection = -SPEED;
        }else if(yDirection == 0){
            yDirection = -SPEED;
            xDirection = -SPEED;
        }else{
            xDirection = -SPEED;
        }
    }

    ballY += yDirection;

    if (ballY <= TOP_BOUNDARY - 2 || ballY >= BOTTOM_BOUNDARY) {
        yDirection = -yDirection;
    }

    drawBall(ballX, ballY);

    //Regeneracion de la linea del medio
    if(xDirection == SPEED && ballX >= (WIDTH / 2) && ballX <= (WIDTH / 2) + BALL_RADIUS * 2){
        for (int i = BALL_RADIUS * -5; i < BALL_RADIUS * 5; i++) {
            putPixel(i + ballY, WIDTH / 2, GREY);
            putPixel(i + ballY, (WIDTH / 2) + 1, GREY);
        }
    }else if(xDirection == -SPEED && ballX <= (WIDTH / 2) && ballX >= (WIDTH / 2) - BALL_RADIUS * 2){
        for (int i = BALL_RADIUS * -5; i < BALL_RADIUS * 5; i++) {
            putPixel(i + ballY, WIDTH / 2, GREY);
            putPixel(i + ballY, (WIDTH / 2) + 1, GREY);
        }
    }

    if(ballX <= 2){
        score2++;
        score = 1;
        undrawBall(ballX, ballY);
        undrawPaddle(PADDLE1_X_POSITION, p1Y);
        undrawPaddle(PADDLE2_X_POSITION, p2Y);
    }else if(ballX >= WIDTH - BALL_RADIUS - 2){
        score1++;
        score = 1;
        undrawBall(ballX, ballY);
        undrawPaddle(PADDLE1_X_POSITION, p1Y);
        undrawPaddle(PADDLE2_X_POSITION, p2Y);
    }
}

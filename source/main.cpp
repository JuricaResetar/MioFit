/*
 *
 *
 */
 
#include "main.h"

#define HEART_X     (70)
#define HEART_Y     (30)


I2C *PO;
Adafruit_SSD1306_I2c *disp;

unsigned int m_z=12434,m_w=33254; 
unsigned int rnd(){
    m_z = 36969 * (m_z & 65535) + (m_z >>16);
    m_w = 18000 * (m_w & 65535) + (m_w >>16);
    return ((m_z <<16) + m_w);
}

void manFigureAnimation(){
    uint8_t counter = 0;
    uint16_t delay = MAN_FIGURE_FRAME_DURATION_MS;
    
    while(counter < MAN_FIGURE_REPS){
        disp->drawBitmap(40,0,manFigure_1, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_2, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_3, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_4, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_5, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_6, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_7, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_8, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_9, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_10, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        disp->drawBitmap(40,0,manFigure_11, 48, 63, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(delay);
        disp->clearDisplay();
        
        counter++;
    }  
}


void heartRate(){
    uint16_t heartRate = 65 + rand()%20;
    disp->setTextColor(WHITE);
    disp->setTextWrap (false);       //mora biti prije upisa u buffer!
    disp->setTextCursor(5,5);
    disp->setTextSize(2);
    disp->printf("Heart rate");
    disp->setTextCursor(20,30);
    disp->setTextSize(4);
    disp->printf("%d", heartRate);
    //disp->printf("77");
    disp->setTextSize(2);
    disp->setTextCursor(70,45);
    disp->printf("/min");
    disp->drawRect(0,0,128,64, WHITE);
    disp->display();
}


int main(){
    wait(START_UP_DELAY_S);
    
    I2C i2c(I2C_SDA,I2C_SCL);
    disp = new Adafruit_SSD1306_I2c(i2c, p23, 0x78, 64, 128);
    
    PO = new I2C(PO_I2C_DATA_PIN, PO_I2C_CLK_PIN);
    MAX30101 myMax = MAX30101(PO,PO_EN_PIN);
    myMax.enable();
    myMax.setupRedLED(255);
    wait_ms(500);
    myMax.setupRedLED(25);
    wait_ms(500);
    
    disp->begin();
 
    while(1){         
        disp->drawBitmap(0,5, mioFitLogo, 127, 57, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(MENU_WAIT_MS);
        disp->clearDisplay();
        disp->display();
        myMax.setupRedLED(255);
        
        heartRate();    
        wait_ms(MENU_WAIT_MS);
        wait_ms(MENU_WAIT_MS);
        disp->clearDisplay();
        myMax.setupRedLED(120);
        
        disp->drawBitmap(0,0, upisiFER, 128, 64, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(MENU_WAIT_MS);
        disp->clearDisplay();
        disp->display();
        myMax.setupRedLED(50);
        
        manFigureAnimation();
        disp->clearDisplay();
        disp->display();
        
        disp->drawBitmap(0,0, ferLogo, 128, 64, WHITE);
        disp->drawRect(0,0,128,64, WHITE);
        disp->display();
        wait_ms(MENU_WAIT_MS);
        disp->clearDisplay();
        disp->display();
        myMax.setupRedLED(10);     
    }
}

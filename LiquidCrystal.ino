// LCD_messageboard
#include <LiquidCrystal.h>

// LiquidCrystal display with:
// rs on pin 8
// rw on pin 11
// enable on pin 9
// d4-7 on pins 4-7
LiquidCrystal lcd(8, 11, 9, 4, 5, 6, 7);
LiquidCrystal lcd2(0, 1, 2, 3, 10, 12, 13);
void setup()
{
    Serial.begin(9600);
    lcd.begin(2, 16);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ajayi");
    lcd.setCursor(0, 1);
    lcd.print("Electronics");
    Serial.begin(9600);
    lcd2.begin(4, 16);
    lcd2.clear();
    lcd2.setCursor(0, 0);
    lcd2.print("Ayomide");
    lcd2.setCursor(0, 1);
    lcd2.print("Engineer");
}
void loop()
{
    if (Serial.available())
    {
        char ch = Serial.read();
        if (ch == '#')
        {
            lcd.clear();
        }
        else if (ch == '/')
        {
            lcd.setCursor(0, 1);
        }
        else
        {
            lcd.write(ch);
        }
    }
}

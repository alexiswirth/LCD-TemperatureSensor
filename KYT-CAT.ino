#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    Serial.begin(9600);
    dht.begin();
    lcd.begin(16, 2);
    lcd.print("Temp: ");
}

void loop()
{
    delay(1000);
    float t = dht.readTemperature();

    if(isnan(t)) {
        Serial.println("Failed to read from DHT sensor !");
        return;
    }
    lcd.print(t);
    lcd.print(" C");
}

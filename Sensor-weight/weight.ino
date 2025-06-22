// الكود الخاص بحساس الوزن HX711 مع ESP32
// هذا الكود يستخدم مكتبة HX711 لقراءة الوزن من حساس HX711 

#include "HX711.h"

// تعريف الأرجل المتصلة مع HX711
#define DOUT 4
#define CLK 5

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(DOUT, CLK);
  Serial.println("بدء الاتصال بحساس الوزن...");

  // التأكد أن الحساس جاهز
  if (scale.is_ready()) {
    Serial.println("تم توصيل الحساس بنجاح");
    scale.set_scale();      // يمكن ضبطه لاحقًا بالقيمة الصحيحة للمعايرة
    scale.tare();           // تصفير الوزن الابتدائي
  } else {
    Serial.println("فشل في الاتصال بالحساس");
    while (1);
  }
}

void loop() {
  long reading = scale.get_units(5);  // قراءة متوسط 5 قراءات للثبات
  Serial.print("الوزن: ");
  Serial.print(reading);
  Serial.println(" غرام");

  delay(1000);
}
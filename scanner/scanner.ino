#define RXD2 16  // توصيل RX من GM65
#define TXD2 17  // توصيل TX من GM65

void setup() {
  Serial.begin(115200);  // لعرض البيانات على Serial Monitor
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);  // الاتصال مع GM65 على UART2

  Serial.println("📦 Scanner Ready... مرر الباركود الآن");
}

void loop() {
  if (Serial2.available()) {
    String barcode = Serial2.readStringUntil('\n');  // قراءة الباركود حتى نهاية السطر
    barcode.trim();  // إزالة الفراغات

    if (barcode.length() > 0) {
      Serial.println("✅ Barcode: " + barcode);  // عرض الباركود في المونيتور
    }
  }
}
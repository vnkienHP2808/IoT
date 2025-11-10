#pragma once

// Cấu hình WiFi
#define WIFI_SSID       "ssid"      // SSID WiFi 
#define WIFI_PASSWORD   "password"  // Mật khẩu

// MQTT Broker
#define MQTT_BROKER     "broker.hivemq.com"     // Địa chỉ public broker
#define MQTT_PORT       1883
#define MQTT_USER       ""
#define MQTT_PASS       ""

// Device infor
#define DEVICE_ID       "esp32-001"                     // Định danh thiết bị (phân biệt khi có nhiều thiết bị khác nhau)
#define LWT_TOPIC       "device/lastwill/" DEVICE_ID    // Last Will and Testament: Đây là topic đặc biệt mà broker sẽ tự động publish khi thiết bị mất kết nối đột ngột => Giám sát online/offline thiết bị

// Topics
#define TOPIC_SENSOR_PUSH       "sensor/data/push"              // Thiết bị gửi dữ liệu cảm biến => Publish
#define TOPIC_DEVICE_CONTROL    "device/control/schedule"       // Nhận lệnh hẹn giờ hoặc tưới tự động từ server => Subcribe
#define TOPIC_DEVICE_FORCE      "device/force/manual"           // Nhận lệnh điều khiển thủ công => Subcribe
#define TOPIC_DASHBOARD_SENSOR  "dashboard/update/sensor"       // Gửi dữ liệu cập nhật realtime lên dashboard => Publish
#define TOPIC_DEVICE_STATUS     "device/status/" DEVICE_ID      // Gửi trạng thái hoạt động/kết nối của thiết bị => Publish
#define TOPIC_DEVICE_LOG        "device/log/" DEVICE_ID         // Gửi log/cảnh báo về server => Publish

// Pins
#define PIN_SOIL_ADC        34      // Analog input của cảm biến độ ẩm đất
#define PIN_PUMP            23      // Relay điều khiển motor
#define PIN_BME             4       // Chân data của BME280
#define PIN_OVERRIDE_BTN    33      // Nút nhấn thủ công bật/tắt bơm

// Timing
#define SENSOR_INTERVAL_MS  30000UL             // Thời gian giữa hai lần đọc cảm biến và gửi dữ liệu là 30s 
#define MQTT_RECONNECT_MS   5000UL              // Thời gian chờ giữa hai lần thử reconnect MQTT là 5s
#define MANUAL_OVERRIDE_TIMEOUT_MS  1200000UL   // Thời gian cho phép chạy bơm ở chế độ thủ công tối đa là 20 phút

// Safety
#define MAX_PUMP_RUNTIME_SEC    600     // Define thời gian bơm mặc định tối đa là 10 phút

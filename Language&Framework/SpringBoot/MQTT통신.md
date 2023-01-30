# MQTT 통신

M2M 또는 IOT를 위한 경량 프로토콜

## MQTT 특징

- Connection Oriented
- Broker
  - Mosquitto
- Pub/Sub Model
  - 브로커를 통해 발행/구독 베세징 패턴으로서 발행측은 브로커에게 벡세지를 전송하며 브로커는 구독하고 있는 클라이언트에게 메세지를 전송
  - 일대일 일대다 통신 가능
- QoS(Quality of Service)
  - 0 : 최대 한번 전송
  - 1 : 최소 1회 전송
  - 2 : 정확히 한 번 수신할 수 있도록 보장
- Topic
  - 토픽은 슬래시(/)로 구분되는 계층구조를 가짐
- LWT(Last Will and testament)
  - 비정상적으로 연결이 끊어짐을 가정
  - 클라이언트와 연결이 끊어지면 자동으로 다른 구독자들에게 메세지가 전송되는 기능


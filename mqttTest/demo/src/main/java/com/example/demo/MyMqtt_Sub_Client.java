package com.example.demo;

/**
 *
 * MQTT 클라이언트 작성 - broker에 메시지를 전달받기 위해 구독신청을 하고 대기하는 객체
 * 1. MqttCallback 인터페이스를 상속
 * 2. MqttCallback 인터페이스의 abstract메소드를 오버라이딩
 *
 */

import org.eclipse.paho.client.mqttv3.*;

public class MyMqtt_Sub_Client implements MqttCallback {
    // broker와 통신하는 역할을 담당 - subscriber, publisher 역할
    private MqttClient mqttclient;
    private MqttConnectOptions mqttConnectOptions;
    // clientId는 broker가 식별하기 위한 무자열
    public MyMqtt_Sub_Client init(String server, String clientId){
        try {
            mqttConnectOptions = new MqttConnectOptions();
            mqttConnectOptions.setCleanSession(true);


            // broker에 subscribe하기 위한 클라이언트 객체 생성
            mqttclient = new MqttClient(server, clientId);
            // 클라이언트 객체에 MqttCallback을 등록 - 구독신청 후 적절한 시점에 처리하고 싶은 기능을 구현하고 메소드가 자동으로 그 시점에 호출되도록 할 수 있음

            mqttclient.setCallback(this);
            mqttclient.connect(mqttConnectOptions);
        } catch (MqttException e) {
            e.printStackTrace();
        }
        return this;
    }

    // 커넥션이 종료되면 호출 - 통신오류로 연결이 끊어지는 경우 호출
    @Override
    public void connectionLost(Throwable throwable) {

    }



    // 메세지가 도착하면 호출되는 메소드
    @Override
    public void messageArrived(String topic, MqttMessage message) throws Exception {
        System.out.println("=================메세지 도착==================");
        System.out.println(message);
        System.out.println("topic:" + topic+ ", id:"+message.getId()+", payload:" + new String(message.getPayload()));

    }

    //구독 신청
    public boolean subscribe(String topic) {
        boolean result = true;
            try {
                if(topic!=null) {
                    // topic과 qos
                    mqttclient.subscribe(topic, 0);
                }
            } catch (MqttException e) {
                e.printStackTrace();
                result = false;
            }
        return result;
    }


    // 메시지의 배달이 완료되면 호출
    @Override
    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {

    }


    public static void main(String[] args) {
        MyMqtt_Sub_Client subobj = new MyMqtt_Sub_Client();
        subobj.init("tcp://3.36.49.220:1883", "myid2").subscribe("iot");
    }
}

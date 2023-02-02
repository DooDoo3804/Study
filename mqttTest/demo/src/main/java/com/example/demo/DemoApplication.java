package com.example.demo;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.MqttPersistenceException;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/***
 *
 * MQTT통신을 통해 메시지를 broker로 전송하기 위한 객체
 * 1. broker 접속
 * 2. broker로 메세지 전송
 *
 */
@SpringBootApplication
public class DemoApplication {

	//MQTT통신에서 publisher와 subscriber의 역할을 하기 위한 기능을 가지고 있는 객체
	private MqttClient client;
	public DemoApplication() {
		try {
			// broker와 MQTT통신을 하며 메ㅔ시지를 전송할 클라이언트 객체를 만들고 접속
			client = new MqttClient("tcp://3.36.49.220:1883", "myid");
			client.connect(); // 접속
		} catch (MqttException e) {
			e.printStackTrace();
		}
	}

	// 메세지 전송을 위한 메소드
	public boolean send(String topic, String msg) {
		try {
			// broker로 전송할 메세지를 생성
			MqttMessage message = new MqttMessage();
			message.setPayload(msg.getBytes()); // 실제 broker로 전송할 메세지
			client.publish(topic, message);
		} catch (MqttPersistenceException e) {
			e.printStackTrace();
		} catch (MqttException e) {
			e.printStackTrace();
		}
		return true;
	}
	// 종료
	public void close() {
		try {
			if(client!=null) {
				client.disconnect();
				client.close();
			}
		} catch (MqttException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		DemoApplication sender = new DemoApplication();
		new Thread(new Runnable() {
			@Override
			public void run() {
				int i=1;
				String msg="";
				while(true) {
					if (i==5) {
						break;
					}
					else {
						if (i%2==1) {
							msg="led_on";
						}else {
							msg = "led_off";
						}
					}
					sender.send("iot", msg);
					i++;
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				sender.close();
			}
		}).start();
		SpringApplication.run(DemoApplication.class, args);
	}

}

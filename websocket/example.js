import React, { useState, useEffect } from 'react';
import Stomp from 'stompjs';

const ChatApp = () => {
  const [client, setClient] = useState(null);
  const [message, setMessage] = useState('');
  const [chatLog, setChatLog] = useState([]);

  useEffect(() => {
    const client = Stomp.client('ws://localhost:8080/stomp');
    client.connect({}, (frame) => {
      setClient(client);
      client.subscribe('/topic/chat', (message) => {
        setChatLog((chatLog) => [...chatLog, JSON.parse(message.body)]);
      });
    });
  }, []);

  const handleSubmit = (event) => {
    event.preventDefault();
    client.send('/app/chat', {}, JSON.stringify({ message }));
    setMessage('');
  };

  useEffect(() => {
    const chatLogContainer = document.getElementById('chat-log');
    chatLogContainer.scrollTop = chatLogContainer.scrollHeight;
  }, [chatLog]);

  return (
    <div>
      <div id="chat-log" style={{ height: '500px', overflowY: 'scroll' }}>
        {chatLog.map((log, index) => (
          <p key={index}>{log.message}</p>
        ))}
      </div>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          value={message}
          onChange={(event) => setMessage(event.target.value)}
        />
        <button type="submit">Send</button>
      </form>
    </div>
  );
};

export default ChatApp;

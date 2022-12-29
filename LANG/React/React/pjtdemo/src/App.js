import './App.css';
import { useState } from 'react';

function App() {

  let [글제목, 글제목변경] = useState(['남자 코트 추천', '강남 우동맛집', '역삼 닭갈비 맛집'])
  let [좋아요, 좋아요변경] = useState(0);

  function like() {
    좋아요변경(좋아요+1);
  }

  function changeTitle() {
    let copy = [...글제목];
    copy[0] = '여자 코트 추천'
    글제목변경(copy);
  }

  function 글소트() {
    let copy = [...글제목]
    copy.sort();
    글제목변경(copy)
  }


  return (
    <div className="App">
      <div className="black-nav">
        <h4>ReactBlog</h4> 
      </div>
      <button onClick={ changeTitle }>글수정</button>
      <button onClick={ 글소트 }>글정렬</button>
      <div className='list'>
        <h4>{ 글제목[0] } <span onClick={ like }>💕</span> { 좋아요 } </h4>
        <p>2월 17일 발행</p>
      </div>
      <div className='list'>
        <h4>{ 글제목[1] }</h4>
        <p>2월 10일 발행</p>
      </div>
      <div className='list'>
        <h4>{ 글제목[2] }</h4>
        <p>2월 25일 발행</p>
      </div>

      <Modal></Modal>
      <Modal/>
    </div>
  );

  function Modal() {
    return (
      <div className='modal'>
        <h4>제목</h4>
        <p>날짜</p>
        <p>상세내용</p>
      </div>

    );
  }

}

export default App;

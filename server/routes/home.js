/* routes/home.js */

// 라우팅을 위한 기본 모듈 포함
const express = require('express'),
  router = express.Router(),
  db = require('./database/db.js');

// '/' 루트 경로 요청시 main 뷰 렌더링
router.get('/', (req, res) => {
  res.render('home/main');
});

// 아두이노에서 데이터 요청시 JSON API 응답
router.post('/arduino', (req, res) => {
  // 클라이언트에게 전달할 데이터 선언
  const data = {
    sensor : 'gps',
    time : 132352342451,
    data : [
      1.5352515,
      4642.5352
    ],
    distance : 2.5
  }; 
  
  // json으로 응답
  res.json(data);
})

// 모듈 내보내기
module.exports = router;
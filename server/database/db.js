/* database/db.js */

// mysql 모듈 포함
const mysql = require('mysql');

// mysql 연결을 위한 인스턴스 생성
const db = mysql.createConnection({
  host: '', // DB 서버 도메인
  user: 'woorimprog', // 지정한 유저 아이디
  password: '', //  지정한 패스워드
  database: 'sensing-dbserver' // 데이터 베이스 이름
});

// 연결 요청
db.connect();

// 외부와 연결시키기 위해 exports
module.exports = db;
/* database/db.js */
const mysql = require('mysql');

const db = mysql.createConnection({
  host: '', // DB 서버 도메인
  user: 'woorimprog', // 지정한 유저 아이디
  password: '', //  지정한 패스워드
  database: 'sensing-dbserver' // 데이터 베이스 이름
});

db.connect();

module.exports = db;
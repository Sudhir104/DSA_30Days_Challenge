# 🚀 Task Manager Backend

A complete RESTful backend built using Node.js, Express, and MongoDB.
This application allows users to manage projects and tasks with secure authentication and role-based access control.

---

## 📌 Project Overview

This backend system provides functionality for:

* User authentication (Signup/Login)
* Role-based access (Admin / Member)
* Project creation and management
* Task assignment and tracking
* Secure API handling using JWT

---

## 🛠 Tech Stack

* Node.js
* Express.js
* MongoDB (Mongoose)
* JWT (Authentication)
* bcryptjs (Password hashing)
* dotenv (Environment variables)
* cors

---

## 📂 Project Structure

task-manager-backend/
│── config/ (Database connection)
│── controllers/ (Business logic)
│── middleware/ (Auth & Role check)
│── models/ (Database schemas)
│── routes/ (API routes)
│── .env (Ignored)
│── .gitignore
│── package.json
│── server.js

---

## ⚙️ Setup Instructions

1. Clone the repository
   git clone https://github.com/Sudhir104/task-manager-backend.git

2. Navigate into project
   cd task-manager-backend

3. Install dependencies
   npm install

4. Create `.env` file and add:
   PORT=5000
   MONGO_URI=your_mongodb_connection_string
   JWT_SECRET=your_secret_key

5. Run the server
   npm run dev

Server will start at:
http://localhost:5000

---

## 🔐 Authentication Flow

* User registers → password is hashed using bcrypt
* User logs in → JWT token is generated
* Token is required to access protected routes

Header format:
Authorization: Bearer <your_token>

---

## 🌐 API Endpoints

### 🔐 Authentication

POST /api/auth/signup
Create a new user

Request Body:
{
"name": "Sudhir",
"email": "[sudhir@gmail.com](mailto:sudhir@gmail.com)",
"password": "123456",
"role": "Admin"
}

Response:
{
"message": "User created",
"user": {
"id": "123",
"name": "Sudhir",
"email": "[sudhir@gmail.com](mailto:sudhir@gmail.com)",
"role": "Admin"
}
}

---

POST /api/auth/login
Login user

Request Body:
{
"email": "[sudhir@gmail.com](mailto:sudhir@gmail.com)",
"password": "123456"
}

Response:
{
"token": "jwt_token",
"user": {
"id": "123",
"name": "Sudhir",
"role": "Admin"
}
}

---

### 📁 Projects (Protected Routes)

POST /api/projects
Create project

GET /api/projects
Get all projects

PUT /api/projects/:id
Update project

DELETE /api/projects/:id
Delete project

Example Request Body:
{
"title": "Task Manager",
"description": "Backend project"
}

---

### ✅ Tasks (Protected Routes)

POST /api/tasks
Create task

GET /api/tasks
Get all tasks

PUT /api/tasks/:id
Update task

DELETE /api/tasks/:id
Delete task

Example Request Body:
{
"title": "Build API",
"description": "Create backend endpoints",
"status": "Pending",
"projectId": "project_id"
}

---

## 🔒 Security Features

* Password hashing using bcrypt
* JWT-based authentication
* Protected routes with middleware
* Role-based authorization

---

## 🧪 Testing

You can test APIs using:

* Postman
* Thunder Client

---

## 🚀 Deployment

This backend can be deployed on:

* Render
* Railway

---

## 📈 Future Improvements

* Pagination and filtering
* Real-time updates (Socket.io)
* Notifications system
* Frontend integration (React)

---

## 👨‍💻 Author

Sudhir Mathur
GitHub: https://github.com/Sudhir104

---

## ⭐ Support

If you like this project, give it a star ⭐ on GitHub.

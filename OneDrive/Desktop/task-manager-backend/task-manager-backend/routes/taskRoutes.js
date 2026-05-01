const express = require("express");
const router = express.Router();
const {
  createTask,
  updateStatus,
  getTasks,
  getDashboardStats
} = require("../controllers/taskController");
const authMiddleware = require("../middleware/authMiddleware");
router.post("/", authMiddleware, createTask);
router.get("/", authMiddleware, getTasks);
router.patch("/:id", authMiddleware, updateStatus);
router.get("/dashboard", authMiddleware, getDashboardStats);

module.exports = router;
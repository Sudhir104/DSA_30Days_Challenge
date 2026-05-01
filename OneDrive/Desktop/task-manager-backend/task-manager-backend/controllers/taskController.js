const Task = require("../models/Task");
const Project = require("../models/Project");
exports.createTask = async (req, res) => {
  try {
    const { title, assignedTo, projectId } = req.body;
    const project = await Project.findById(projectId);
    if (!project) {
      return res.status(404).json({ message: "Project not found" });
    }
    if (project.owner.toString() !== req.user._id.toString()) {
      return res.status(403).json({ message: "Only owner can create tasks" });
    }
    const task = await Task.create({
      title,
      project: projectId, 
      assignedTo,
      createdBy: req.user._id,
      status: "pending"
    });
    res.status(201).json(task);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
exports.getTasks = async (req, res) => {
  try {
    const tasks = await Task.find({
      $or: [
        { assignedTo: req.user._id },
        { createdBy: req.user._id }
      ]
    })
      .populate("project", "name")
      .populate("assignedTo", "email");
    res.json(tasks);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
exports.updateStatus = async (req, res) => {
  try {
    const task = await Task.findById(req.params.id);
    if (!task) {
      return res.status(404).json({ message: "Task not found" });
    }
    const isAllowed =
      task.assignedTo?.toString() === req.user._id.toString() ||
      task.createdBy.toString() === req.user._id.toString();
    if (!isAllowed) {
      return res.status(403).json({ message: "Not allowed" });
    }
    task.status = req.body.status || task.status;
    await task.save();
    res.json(task);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
exports.getDashboardStats = async (req, res) => {
  try {
    const total = await Task.countDocuments({
      $or: [
        { assignedTo: req.user._id },
        { createdBy: req.user._id }
      ]
    });
    const completed = await Task.countDocuments({
      status: "done",
      $or: [
        { assignedTo: req.user._id },
        { createdBy: req.user._id }
      ]
    });
    const pending = await Task.countDocuments({
      status: "pending",
      $or: [
        { assignedTo: req.user._id },
        { createdBy: req.user._id }
      ]
    });
    res.json({
      totalTasks: total,
      completedTasks: completed,
      pendingTasks: pending
    });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
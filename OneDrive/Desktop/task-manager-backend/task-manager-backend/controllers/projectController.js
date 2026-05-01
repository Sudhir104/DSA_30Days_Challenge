const Project = require("../models/Project");
exports.createProject = async (req, res) => {
  try {
    const { name, description, members } = req.body;
    const project = await Project.create({
      name,
      description,
      owner: req.user._id, 
      members: members || []
    });
    res.status(201).json(project);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
exports.getProjects = async (req, res) => {
  try {
    const projects = await Project.find({
      $or: [
        { owner: req.user._id },
        { members: req.user._id }
      ]
    }).populate("owner members", "email role");

    res.json(projects);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
exports.addMember = async (req, res) => {
  try {
    const { userId } = req.body;
    const project = await Project.findById(req.params.id)
    if (!project) {
      return res.status(404).json({ message: "Project not found" });
    }
    if (project.owner.toString() !== req.user._id.toString()) {
      return res.status(403).json({ message: "Only owner can add members" });
    }
    project.members.push(userId);
    await project.save();
    res.json(project);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};
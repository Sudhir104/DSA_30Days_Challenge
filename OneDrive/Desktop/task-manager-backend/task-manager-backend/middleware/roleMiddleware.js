module.exports = (allowedRoles = []) => {
  return (req, res, next) => {
    if (!req.user || !req.user.role) {
      return res.status(401).json({ message: "User not authenticated" });
    }
    const roles = Array.isArray(allowedRoles)
      ? allowedRoles.map(r => r.toLowerCase())
      : [allowedRoles.toLowerCase()];
    const userRole = req.user.role.toLowerCase();
    if (!roles.includes(userRole)) {
      return res.status(403).json({ message: "Access denied" });
    }
    next();
  };
};
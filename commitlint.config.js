module.exports = {
  extends: ["@commitlint/config-conventional"],
  rules: {
    "type-enum": [
      2, // error: 2, warning: 1, off: 0
      "always",
      ["feat", "fix", "refactor", "Revert"],
    ],
    "scope-enum": [2, "always", ["SRC", "DOC", "CI", "ENV"]],
    "header-max-length": [2, "always", 64],
    "scope-empty": [2, "never"],
    "subject-empty": [2, "never"],
  },
};

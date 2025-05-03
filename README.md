# CSC Project - University Management System (UMS)

This project is a CSV-based University Management System designed to simulate a minimal academic portal with user roles such as Student, Faculty, and Admin. It supports login/registration, dashboards, attendance tracking, grades, messaging, and more.

## 🔑 Authentication Flow

- **Login / Registration → Verify Role → Redirect to Dashboard**

**Required File:**
- `users.csv` — Format: `id,username,password,role` (student/faculty/admin)

**Functions:**
- `registerUser()` — Prompts for username, password, and role; appends to `users.csv`.
- `loginUser()` — Validates credentials against `users.csv`.
- `getRoleById()` — Fetches user role after login for dashboard redirection.

---

## 🎓 Student Dashboard

1. **View Report Card (CGPA)**
   - Source: `grades.csv` — Format: `student_id,course_id,grade`
   - Computes CGPA using simple average.

2. **View Attendance**
   - Source: `attendance.csv` — Format: `student_id,course_id,date,status`
   - Shows attendance percentage by course.

3. **View Course Info**
   - Source: `courses.csv` — Format: `course_id,course_name,instructor_id`
   - Joined with `student_course.csv` for enrolled courses.

4. **View Leaderboards**
   - Uses `grades.csv` to rank students by CGPA.

5. **Pay Fees (Optional)**
   - Source: `fees.csv` — Format: `student_id,status,amount_due`
   - Displays fee status and allows simulated payment.

6. **Messaging**
   - Source: `messages.csv` — Format: `sender_id,receiver_role,message,timestamp`
   - **Chatbot (FAQ):** Uses `faq.csv` — Format: `question,answer`
   - **Send Message:** One-way message to faculty/admin.

---

## 👨‍🏫 Faculty Dashboard

1. **Upload Course Info**
   - Appends to `courses.csv` (validates faculty ID).

2. **Update Attendance**
   - Adds new entries to `attendance.csv`.

3. **Input/Edit Grades**
   - Modifies `grades.csv` entries.

4. **Messaging**
   - Uses `messages.csv`, with filtering by role and permission.

---

## 👩‍💼 Admin Dashboard

1. **Process Admissions**
   - Adds new students to `users.csv` and `student_course.csv`.

2. **Manage Fees**
   - Updates `fees.csv` with amounts and payment status.

3. **Update FAQ (Chatbot KB)**
   - Edits `faq.csv` (add/edit/remove questions/answers).

4. **Edit Curriculum**
   - Updates course offerings in `courses.csv`.

5. **Messaging**
   - Broadcasts messages (`receiver_role=all`) or targets by role.

---

## 📂 CSV File Summary

| File               | Description                              |
|--------------------|------------------------------------------|
| `users.csv`        | `id,username,password,role`              |
| `grades.csv`       | `student_id,course_id,grade`             |
| `attendance.csv`   | `student_id,course_id,date,status`       |
| `courses.csv`      | `course_id,course_name,instructor_id`    |
| `fees.csv`         | `student_id,status,amount_due`           |
| `faq.csv`          | `question,answer`                        |
| `messages.csv`     | `sender_id,receiver_role,message,timestamp` |
| `student_course.csv` | `student_id,course_id`                 |

---

## 📌 Notes

- All data is managed via flat CSV files.
- Ideal for academic demonstration or prototyping without a database.

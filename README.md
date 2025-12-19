Local Event-Driven Task Scheduler (C++ / CLI)

این پروژه یک موتور زمان‌بندی وظایف (Task Scheduler) سبک و لوکال است که با رویکرد event-driven و با استفاده از Modern C++ پیاده‌سازی شده است.
هدف پروژه مدیریت اجرای وظایف مستقل یا وابسته، با پشتیبانی از اولویت‌بندی و اجرای ترتیبی در یک محیط Command-Line می‌باشد.

این سیستم برای سناریوهایی مانند Render Pipelineها، اجرای Batch Commandها و Jobهای پردازشی طراحی شده و تمرکز اصلی آن روی طراحی تمیز، مدیریت منابع، Thread-Safety و Extensibility است.

پروژه به‌صورت CLI اجرا می‌شود و فاقد Live URL است؛ خروجی اجرای واقعی آن در محیط Cloud (Render) در تصویر زیر قابل مشاهده است.

![Render Execution Output](docs/Render.png)


 ویژگی‌ها

این Task Scheduler قابلیت‌های زیر را فراهم می‌کند:

پیاده‌سازی Event-Driven Task Scheduling

پشتیبانی از اجرای وظایف با اولویت (Priority-based)

مدیریت وابستگی بین وظایف (Task Dependencies)

اجرای امن چندریسمانی (Thread-Safe Execution)

استفاده از RAII و Smart Pointerها برای مدیریت منابع

طراحی ماژولار و قابل توسعه

مناسب برای Render Jobها و Command Pipelineها

بدون وابستگی به UI یا سرویس خارجی

 پیش‌نیازها

C++17 یا بالاتر

CMake

GCC / Clang / MSVC

Linux / macOS / Windows

(اختیاری)

Docker یا WSL برای اجرای ایزوله

 نصب و اجرا (CLI)
Build با CMake
mkdir build
cd build
cmake ..
cmake --build . --config Release

اجرا
./task_scheduler

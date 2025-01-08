from datetime import datetime

now = datetime.now()

past_date_string = "January 1, 1970"
past = datetime.strptime(past_date_string, "%B %d, %Y")

diff = now - past
total_seconds = diff.total_seconds()
print(f"Seconds since {past_date_string}: {total_seconds:,} or {total_seconds:.2e} in scientific notation")
print(now.strftime("%b %d %Y"))
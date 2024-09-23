package com.example.alarm_service;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText edtMinutes, edtSeconds;
    Button btnStartTimer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtMinutes = findViewById(R.id.edtMinutes);
        edtSeconds = findViewById(R.id.edtSeconds);
        btnStartTimer = findViewById(R.id.btnStartTimer);

        btnStartTimer.setOnClickListener(view -> {

            String minutesText = edtMinutes.getText().toString();
            String secondsText = edtSeconds.getText().toString();


            int minutes = !minutesText.isEmpty() ? Integer.parseInt(minutesText) : 0;
            int seconds = !secondsText.isEmpty() ? Integer.parseInt(secondsText) : 0;


            int totalMillis = (minutes * 60 + seconds) * 1000;

            if (totalMillis > 0) {

                Intent intent = new Intent(MainActivity.this, Alarm.class);
                AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
                PendingIntent pendingIntent = PendingIntent.getBroadcast(getApplicationContext(), 0, intent, PendingIntent.FLAG_IMMUTABLE);

                alarmManager.set(AlarmManager.RTC_WAKEUP, System.currentTimeMillis() + totalMillis, pendingIntent);

                Toast.makeText(MainActivity.this, "Будильник установлен на " + minutes + " минут(ы) и " + seconds + " секунд(ы)", Toast.LENGTH_SHORT).show();
            }
        });
    }
}

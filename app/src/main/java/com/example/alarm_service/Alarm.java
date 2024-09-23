package com.example.alarm_service;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Vibrator;
import android.widget.Toast;

public class Alarm extends BroadcastReceiver {
    private MediaPlayer mediaPlayer;

    @Override
    public void onReceive(Context context, Intent intent) {
        Toast.makeText(context, "Будильник завершен!", Toast.LENGTH_LONG).show();

        Vibrator vibrator = (Vibrator) context.getSystemService(Context.VIBRATOR_SERVICE);
        if (vibrator != null) {
            vibrator.vibrate(1000);
        }
        mediaPlayer = MediaPlayer.create(context, R.raw.music);
        mediaPlayer.start();
        mediaPlayer.setOnCompletionListener(mp -> stopAlarm());
    }


    private void stopAlarm() {
        if (mediaPlayer != null) {
            mediaPlayer.stop();
            mediaPlayer.release();
            mediaPlayer = null;
        }
    }
}

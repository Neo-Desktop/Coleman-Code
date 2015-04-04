Public Class MainForm

    Private Sub MainForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        Application.Exit()
    End Sub

    Private Sub DefaultToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles DefaultToolStripMenuItem.Click
        Dim lnof = New OptionsForm()
        If (lnof.ShowDialog() = Windows.Forms.DialogResult.OK) Then
            RefreshData()
        End If
    End Sub

    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox1.SelectedIndexChanged
        If ListBox1.SelectedIndex >= 0 Then
            Dim selectedFile As FileData = ListBox1.Items(ListBox1.SelectedIndex)
            Dim holdTime = selectedFile.FileTime + Options.PlaylistTime

            If holdTime <= Options.PlaylistLength Then
                Button1.Enabled = True
            Else
                Button1.Enabled = False
            End If
        End If
    End Sub

    Private Sub ListBox2_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox2.SelectedIndexChanged
        If ListBox2.SelectedIndex >= 0 Then
            Button4.Enabled = True
        Else
            Button4.Enabled = False
        End If
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If ListBox1.SelectedIndex >= 0 Then
            Dim file As FileData = ListBox1.Items(ListBox1.SelectedIndex)
            ListBox1.Items.RemoveAt(ListBox1.SelectedIndex)
            RemoveFileFromTotal(file)
            ListBox2.Items.Add(file)
            AddFileToPlaylist(file)
        End If
        ListBox1.SelectedIndex = -1
        Button1.Enabled = False
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Button1.Enabled = False
        Button2.Enabled = False
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Button3.Enabled = False
        Button4.Enabled = False
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        If ListBox2.SelectedIndex >= 0 Then
            Dim file As FileData = ListBox2.Items(ListBox2.SelectedIndex)
            ListBox2.Items.RemoveAt(ListBox2.SelectedIndex)
            RemoveFileFromPlaylist(file)
            ListBox1.Items.Add(file)
            AddFileToTotal(file)
        End If
        ListBox2.SelectedIndex = -1
        Button4.Enabled = False
    End Sub


    Public Sub RefreshData()
        ' MessageBox.Show("Do we halt here", "I dunno", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
        Options.TotalTime = 0
        Options.PlaylistTime = 0
        AddFileToTotal(New FileData("", 0))
        AddFileToPlaylist(New FileData("", 0))

        ListBox1.Items.Clear()
        ListBox2.Items.Clear()

        Dim iSpan As TimeSpan = TimeSpan.FromSeconds(Options.PlaylistLength)
        Dim formattedTime As String = String.Empty
        If iSpan.Hours > 0 Then
            formattedTime = iSpan.Hours.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        Else
            formattedTime = iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        End If
        Label6.Text = formattedTime

        For Each foundFile As String In My.Computer.FileSystem.GetFiles(Options.Directory)
            foundFile = My.Computer.FileSystem.GetName(foundFile)
            Dim foundExt = System.IO.Path.GetExtension(foundFile)
            For Each lext As String In Options.ExtensionsList
                If foundExt = lext Then
                    Dim randomTime As Integer = CInt(Int(((6 * 60) * Rnd()) + 60))
                    Dim file As New FileData(foundFile, randomTime)
                    ListBox1.Items.Add(file)
                    AddFileToTotal(file)
                End If
            Next
        Next
        If ListBox1.Items.Count > 0 Then
            Button2.Enabled = True
        Else
            Button2.Enabled = False
        End If
    End Sub

    Private Sub AddFileToTotal(file As FileData)
        Options.TotalTime += file.FileTime
        Dim formattedTime As String = String.Empty
        Dim iSpan As TimeSpan = TimeSpan.FromSeconds(Options.TotalTime)
        If iSpan.Hours > 0 Then
            formattedTime = iSpan.Hours.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        Else
            formattedTime = iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        End If
        Label3.Text = formattedTime

    End Sub

    Private Sub RemoveFileFromTotal(file As FileData)
        Options.TotalTime -= file.FileTime
        Dim formattedTime As String = String.Empty
        Dim iSpan As TimeSpan = TimeSpan.FromSeconds(Options.TotalTime)
        If iSpan.Hours > 0 Then
            formattedTime = iSpan.Hours.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        Else
            formattedTime = iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        End If
        Label3.Text = formattedTime
    End Sub

    Private Sub AddFileToPlaylist(file As FileData)
        Options.PlaylistTime += file.FileTime
        Dim formattedTime As String = String.Empty
        Dim iSpan As TimeSpan = TimeSpan.FromSeconds(Options.PlaylistTime)
        If iSpan.Hours > 0 Then
            formattedTime = iSpan.Hours.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        Else
            formattedTime = iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        End If
        Label2.Text = formattedTime
    End Sub

    Private Sub RemoveFileFromPlaylist(file As FileData)
        Options.PlaylistTime -= file.FileTime
        Dim formattedTime As String = String.Empty
        Dim iSpan As TimeSpan = TimeSpan.FromSeconds(Options.PlaylistTime)
        If iSpan.Hours > 0 Then
            formattedTime = iSpan.Hours.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        Else
            formattedTime = iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        End If
        Label2.Text = formattedTime
    End Sub
End Class
